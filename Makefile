build-cpp :
	mkdir -p build/
	cd build/; cmake ../lib/; $(MAKE)

build-rust :
	cd bindings/rust/; cargo build --release

build-py :
	cd bindings/python/; python3 setup.py bdist_wheel

clean-cpp :
	rm -rf build/

clean-rust:
	rm -rf bindings/rust/target/

clean-py :
	rm -rf bindings/python/build/ bindings/python/dist/ bindings/python/pylibuuas.egg-info/ bindings/python/pylibuuas/_libuuas*

clean : clean-cpp clean-rust clean-py
