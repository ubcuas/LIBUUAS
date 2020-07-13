import cppyy

cppyy.include('libuuas/uuas.hpp')
cppyy.load_library('/usr/local/lib/libuuas.so')

