import setuptools

setuptools.setup(
    name="pylibuuas",
    version="0.1.0",
    author="Eric Mikulin",
    packages=setuptools.find_packages(),
    setup_requires=["cffi>=1.0.0"],
    cffi_modules=["pylibuuas/libuuas_build.py:ffi"],
    install_requires=["cffi>=1.0.0"],
    python_requires='>=3.8',
)
