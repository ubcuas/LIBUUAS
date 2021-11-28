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

## Test ##
test-cpp: build-cpp
	cd build; make test

test-rust:
	cd bindings/rust/; cargo test --release

test-py:
	docker run -it ubcuas/pyuuas bash /home/python-tests/tests/run-tests.sh;

test: test-cpp test-rust test-py

## Lint ##
lint-cpp:
	cd lib/; find . -regex '.*\.\(cpp\|hpp\)' -exec clang-format -style=file -i {} \;

lint-rust:
	cd bindings/rust/; cargo fmt

lint-py:
	pip3 install --user mypy autopep8
	cd bindings/python/; find . -name '*.py' | grep -v uuaspb_pb2.py | xargs autopep8 --in-place
# 	cd bindings/python/; find pylibuuas/ -name '*.py' | grep -v uuaspb_pb2.py | xargs mypy

lint: lint-cpp lint-rust lint-py

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
	pip3 install --user --upgrade --no-deps --force-reinstall bindings/python/dist/*.whl

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
	docker build . --pull=true --target cpprun -t ubcuas/cppuuas:latest

docker-cpp-publish: docker-cpp
	docker push ubcuas/cppuuas:latest

docker-cpp-multiarch: docker-multiarch-deps
	DOCKER_CLI_EXPERIMENTAL=enabled \
	DOCKER_BUILDKIT=enabled \
	docker buildx build . --pull=true --target cpprun -t ubcuas/cppuuas:latest --platform "linux/amd64,linux/arm64,linux/arm/v7"

docker-cpp-multiarch-publish: docker-multiarch-deps
	DOCKER_CLI_EXPERIMENTAL=enabled \
	DOCKER_BUILDKIT=enabled \
	docker buildx build . --pull=true --target cpprun -t ubcuas/cppuuas:latest --push --platform "linux/amd64,linux/arm64,linux/arm/v7"

docker-rust:
	docker build . --pull=true --target rustrun -t ubcuas/rustuuas:latest

docker-rust-publish: docker-rust
	docker push ubcuas/rustuuas:latest

docker-rust-multiarch: docker-multiarch-deps
	DOCKER_CLI_EXPERIMENTAL=enabled \
	DOCKER_BUILDKIT=enabled \
	docker buildx build . --pull=true --target rustrun -t ubcuas/rustuuas:latest --platform "linux/amd64,linux/arm64,linux/arm/v7"

docker-rust-multiarch-publish: docker-multiarch-deps
	DOCKER_CLI_EXPERIMENTAL=enabled \
	DOCKER_BUILDKIT=enabled \
	docker buildx build . --pull=true --target rustrun -t ubcuas/rustuuas:latest --push --platform "linux/amd64,linux/arm64,linux/arm/v7"

docker-py:
	docker build . --pull=true --target pyrun -t ubcuas/pyuuas:latest
	docker build . --pull=true --target pypyrun -t ubcuas/pypyuuas:latest

docker-py-publish: docker-py
	docker push ubcuas/pyuuas:latest
	docker push ubcuas/pypyuuas:latest

docker-py-multiarch: docker-multiarch-deps
	DOCKER_CLI_EXPERIMENTAL=enabled \
	DOCKER_BUILDKIT=enabled \
	docker buildx build . --pull=true --target pyrun -t ubcuas/pyuuas:latest  --platform "linux/amd64"
	DOCKER_CLI_EXPERIMENTAL=enabled \
	DOCKER_BUILDKIT=enabled \
	docker buildx build . --pull=true --target pypyrun -t ubcuas/pypyuuas:latest  --platform "linux/amd64"

docker-py-multiarch-publish: docker-multiarch-deps
	DOCKER_CLI_EXPERIMENTAL=enabled \
	DOCKER_BUILDKIT=enabled \
	docker buildx build . --pull=true --target pyrun -t ubcuas/pyuuas:latest --push --platform "linux/amd64"
	DOCKER_CLI_EXPERIMENTAL=enabled \
	DOCKER_BUILDKIT=enabled \
	docker buildx build . --pull=true --target pypyrun -t ubcuas/pypyuuas:latest --push --platform "linux/amd64"

docker-multiarch-publish: docker-cpp-multiarch-publish docker-rust-multiarch-publish docker-py-multiarch-publish
docker-multiarch: docker-cpp-multiarch docker-rust-multiarch docker-py-multiarch
docker-publish: docker-cpp-publish docker-rust-publish docker-py-publish
docker: docker-cpp docker-rust docker-py
