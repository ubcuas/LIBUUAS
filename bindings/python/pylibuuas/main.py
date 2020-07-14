import cppyy

cppyy.include('libuuas/bindings.hpp')
cppyy.load_library('/usr/local/lib/libuuas.so')

