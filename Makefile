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
	pip3 install bindings/python/dist/*.whl

install: install-cpp install-rust install-py

## Protobuf ##
protobuf-cpp:
	cd shared/protobufs/; protoc uuaspb.proto --cpp_out=$(CURDIR)/lib/src/libuuas

protobuf-rust:
	cargo install protobuf-codegen --version="2.16.2";
	cd shared/protobufs/; PATH="$(HOME)/.cargo/bin:$(PATH)" protoc uuaspb.proto --rust_out=$(CURDIR)/bindings/rust/src

protobuf-py:
	cd shared/protobufs/; protoc uuaspb.proto --python_out=$(CURDIR)/bindings/python/pylibuuas

protobuf: protobuf-cpp protobuf-rust protobuf-py

## Docker ##
docker-cpp:
	docker build . --target cpprun -t ubcuas/cppuuas:latest

docker-cpp-publish: docker-cpp
	docker push ubcuas/cppuuas:latest

docker-rust:
	docker build . --target rustrun -t ubcuas/rustuuas:latest

docker-rust-publish: docker-rust
	docker push ubcuas/rustuuas:latest

docker-py:
	docker build . --target pyrun -t ubcuas/pyuuas:latest

docker-py-publish: docker-py
	docker push ubcuas/pyuuas:latest

docker-publish: docker-cpp-publish docker-rust-publish docker-py-publish
docker: docker-cpp docker-rust docker-py
