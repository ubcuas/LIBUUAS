import cppyy
import uuaspb_pb2

cppyy.include('libuuas/uuas.hpp')
cppyy.load_library('/usr/local/lib/libuuas.so')
print(cppyy.gbl.double_nums(45, 22))

