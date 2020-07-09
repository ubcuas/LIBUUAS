import cppyy
cppyy.include('libuuas/uuas.hpp')
cppyy.load_library('/usr/local/lib/libuuas.so')
print(cppyy.gbl.double_nums(45, 22))
