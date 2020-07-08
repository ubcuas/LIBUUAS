import cffi
import pathlib

print("Building CFFI Module")
ffi = cffi.FFI()

wrapper_h_filename = f"/usr/local/include/libuuas/uuas.hpp"
with open(wrapper_h_filename) as h_file:
    ffi.cdef(h_file.read())

ffi.set_source(
    "pylibuuas._libuuas",
    '#include "/usr/local/include/libuuas/uuas.hpp"',
    libraries=["uuas"],
    library_dirs=[pathlib.Path("/usr/local/lib/").as_posix()],
    include_dirs=[pathlib.Path("/usr/local/include/").as_posix()],
)

if __name__ == "__main__":
    ffi.compile(verbose=True)
