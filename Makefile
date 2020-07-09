## Util ##
list:
	@$(MAKE) -pRrq -f $(lastword $(MAKEFILE_LIST)) : 2>/dev/null | awk -v RS= -F: '/^# File/,/^# Finished Make data base/ {if ($$1 !~ "^[#.]") {print $$1}}' | sort | egrep -v -e '^[^[:alnum:]]' -e '^$@$$'

## Build ##
build-cpp :
	mkdir -p build/
	cd build/; cmake ../lib/; $(MAKE)

build-rust :
	cd bindings/rust/; cargo build --release

build-py :
	cd bindings/python/; python3 pylibuuas/libuuas_build.py; python3 setup.py bdist_wheel

## Cleanup ##
clean-cpp :
	rm -rf build/

clean-rust:
	rm -rf bindings/rust/target/

clean-py :
	rm -rf bindings/python/build/ bindings/python/dist/ bindings/python/pylibuuas.egg-info/ bindings/python/pylibuuas/_libuuas*

clean : clean-cpp clean-rust clean-py

## Protobuf ##
protobuf-cpp :
	cd shared/protobufs/; protoc uuaspb.proto --cpp_out=$(CURDIR)/lib/src/libuuas

## Docker ##
docker-cpp :
	docker build . --target cpprun -t ubcuas/cppuuas:latest

docker-cpp-publish :
	docker push ubcuas/cppuuas:latest

docker-rust :
	docker build . --target rustrun -t ubcuas/rustuuas:latest

docker-rust-publish :
	docker push ubcuas/rustuuas:latest

docker-py :
	docker build . --target pyrun -t ubcuas/pyuuas:latest

docker-py-publish :
	docker push ubcuas/pyuuas:latest

docker-publish : docker-cpp-publish docker-rust-publish docker-py-publish

docker : docker-cpp docker-rust docker-py
