## Util ##
list:
	@$(MAKE) -pRrq -f $(lastword $(MAKEFILE_LIST)) : 2>/dev/null | awk -v RS= -F: '/^# File/,/^# Finished Make data base/ {if ($$1 !~ "^[#.]") {print $$1}}' | sort | egrep -v -e '^[^[:alnum:]]' -e '^$@$$'

## Build ##
build-cpp:
	mkdir -p build/
	cd build/; cmake ../lib/; $(MAKE)

build-rust:
	cd bindings/rust/; cargo build --release

build-py:
	cd bindings/python/; python3 setup.py bdist_wheel

build: build-cpp build-rust build-py

## Lint ##
lint-cpp:
	cd lib/; find . -regex '.*\.\(cpp\|hpp\)' -exec clang-format -style=file -i {} \;

lint-rust:
	cd bindings/rust/; cargo fmt

lint: lint-cpp lint-rust

## Cleanup ##
clean-cpp:
	rm -rf build/

clean-rust:
	rm -rf bindings/rust/target/

clean-py:
	rm -rf bindings/python/build/ bindings/python/dist/ bindings/python/pylibuuas.egg-info/

clean: clean-cpp clean-rust clean-py

## Install ##
install-cpp: build-cpp
	cd build/; sudo $(MAKE) install

install-rust: build-rust
	sudo mkdir -p /opt/ruuas/
	sudo cp -r bindings/rust/* /opt/ruuas/

install-py: build-py
	pip3 install --user --force-reinstall bindings/python/dist/*.whl

install: install-cpp install-rust install-py

## Protobuf ##
protobuf-cpp:
	cd shared/protobufs/; protoc uuaspb.proto --cpp_out=$(CURDIR)/lib/src/libuuas

protobuf-rust:
	cargo install protobuf-codegen --version="2.16.2"
	cd shared/protobufs/; PATH="$(HOME)/.cargo/bin:$(PATH)" protoc uuaspb.proto --rust_out=$(CURDIR)/bindings/rust/src

protobuf-py:
	cd shared/protobufs/; protoc uuaspb.proto --python_out=$(CURDIR)/bindings/python/pylibuuas

protobuf: protobuf-cpp protobuf-rust protobuf-py

## Docker ##
docker-multiarch-deps:
	DOCKER_CLI_EXPERIMENTAL=enabled DOCKER_BUILDKIT=enabled docker run --rm --privileged multiarch/qemu-user-static --reset -p yes
	DOCKER_CLI_EXPERIMENTAL=enabled DOCKER_BUILDKIT=enabled docker buildx create --name mubuilder | echo "ok"
	DOCKER_CLI_EXPERIMENTAL=enabled DOCKER_BUILDKIT=enabled docker buildx use mubuilder
	DOCKER_CLI_EXPERIMENTAL=enabled DOCKER_BUILDKIT=enabled docker buildx inspect --bootstrap

docker-cpp:
	docker build . --target cpprun -t ubcuas/cppuuas:latest

docker-cpp-publish: docker-cpp
	docker push ubcuas/cppuuas:latest

docker-cpp-multiarch-publish: docker-multiarch-deps
	DOCKER_CLI_EXPERIMENTAL=enabled \
	DOCKER_BUILDKIT=enabled \
	docker buildx build . --target cpprun -t ubcuas/cppuuas:multiarch --push --platform "linux/amd64,linux/arm64,linux/arm/v7"

docker-rust:
	docker build . --target rustrun -t ubcuas/rustuuas:latest

docker-rust-publish: docker-rust
	docker push ubcuas/rustuuas:latest

docker-rust-multiarch-publish: docker-multiarch-deps
	DOCKER_CLI_EXPERIMENTAL=enabled \
	DOCKER_BUILDKIT=enabled \
	docker buildx build . --target rustrun -t ubcuas/rustuuas:multiarch --push --platform "linux/amd64,linux/arm64,linux/arm/v7"

docker-py:
	docker build . --target pyrun -t ubcuas/pyuuas:latest
	docker build . --target pypyrun -t ubcuas/pypyuuas:latest

docker-py-publish: docker-py
	docker push ubcuas/pyuuas:latest
	docker push ubcuas/pypyuuas:latest

docker-py-multiarch-publish: docker-multiarch-deps
	DOCKER_CLI_EXPERIMENTAL=enabled \
	DOCKER_BUILDKIT=enabled \
	docker buildx build . --target pyrun -t ubcuas/pyuuas:multiarch --push --platform "linux/amd64,linux/arm64,linux/arm/v7"
	DOCKER_CLI_EXPERIMENTAL=enabled \
	DOCKER_BUILDKIT=enabled \
	docker buildx build . --target pypyrun -t ubcuas/pypyuuas:multiarch --push --platform "linux/amd64,linux/arm64,linux/arm/v7"

docker-multiarch-publish: docker-cpp-multiarch-publish docker-rust-multiarch-publish docker-py-multiarch-publish
docker-publish: docker-cpp-publish docker-rust-publish docker-py-publish
docker: docker-cpp docker-rust docker-py
