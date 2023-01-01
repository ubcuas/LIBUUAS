import setuptools

setuptools.setup(
    name="pylibuuas",
    version="0.1.0",
    author="Eric Mikulin",
    packages=setuptools.find_packages(),
    install_requires=["cppyy>=1.7.1", "protobuf==3.18.3"],
    python_requires='>=3.6',
)
