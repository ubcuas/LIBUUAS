#### Libuuas build image ####
FROM itseris/cmake:latest AS libbuild
RUN mkdir -p /libuuas/
WORKDIR /libuuas/

RUN apt-get --allow-releaseinfo-change-suite update -y && apt-get install -y build-essential zlib1g-dev libexpat1-dev libwebp-dev

RUN mkdir -p /libuuas/build/
WORKDIR /libuuas/build/

RUN mkdir -p /libuuas/lib/
COPY lib/ /libuuas/lib/

RUN cmake /libuuas/lib/
RUN make -j$(nproc)
RUN make install


#### C++ runtime image ####
FROM debian:bullseye AS cpprun

COPY --from=libbuild /usr/local/lib/ /usr/local/lib/
COPY --from=libbuild /usr/local/include/ /usr/local/include/
RUN ldconfig /usr/local/lib/


#### Rust bindings build image ####
FROM rust:1.56.0-bullseye AS rustbuild
RUN mkdir -p /libuuas/
WORKDIR /libuuas/

RUN apt-get update -y && apt-get install -y llvm clang

COPY --from=libbuild /usr/local/lib/ /usr/local/lib/
COPY --from=libbuild /usr/local/include/ /usr/local/include/
RUN ldconfig /usr/local/lib/

COPY bindings/rust/ /libuuas/build
WORKDIR /libuuas/build/
RUN cargo build --release


#### Rust runtime image ####
FROM rust:1.56.0-bullseye AS rustrun
RUN mkdir -p /libuuas/
RUN mkdir -p /opt/ruuas/

RUN apt-get update -y && apt-get install -y llvm clang

COPY --from=libbuild /usr/local/lib/ /usr/local/lib/
COPY --from=libbuild /usr/local/include/ /usr/local/include/
RUN ldconfig /usr/local/lib/

COPY bindings/rust/ /opt/ruuas/


#### Python bindings build image ####
FROM python:3.8 AS pybuild
RUN mkdir -p /libuuas/
WORKDIR /libuuas/

RUN apt-get update -y && apt-get install -y cmake
RUN pip install --verbose cppyy

COPY bindings/python/build_requirements.txt ./
RUN pip install -r build_requirements.txt

COPY --from=libbuild /usr/local/lib/ /usr/local/lib/
COPY --from=libbuild /usr/local/include/ /usr/local/include/
RUN ldconfig /usr/local/lib/

COPY bindings/python/ ./build
WORKDIR /libuuas/build/
RUN python3 setup.py bdist_wheel


#### Python runtime image ####
FROM python:3.8 AS pyrun

RUN apt-get update -y && apt-get install -y cmake
RUN pip install --verbose cppyy

COPY --from=libbuild /usr/local/lib/ /usr/local/lib/
COPY --from=libbuild /usr/local/include/ /usr/local/include/
RUN ldconfig /usr/local/lib/

COPY --from=pybuild /libuuas/build/dist/*.whl ./
RUN pip install *.whl
RUN rm -rf *.whl


#### Pypy runtime image ####
FROM pypy:3.8-bullseye AS pypyrun

RUN apt-get update -y && apt-get install -y cmake
RUN pip install --verbose cppyy

COPY --from=libbuild /usr/local/lib/ /usr/local/lib/
COPY --from=libbuild /usr/local/include/ /usr/local/include/
RUN ldconfig /usr/local/lib/

COPY --from=pybuild /libuuas/build/dist/*.whl ./
RUN pip install *.whl
RUN rm -rf *.whl
