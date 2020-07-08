#### Libuuas build image ####
FROM itseris/cmake:latest AS libbuild
RUN mkdir -p /libuuas/
WORKDIR /libuuas/

RUN apt-get update -y && apt-get install -y build-essential zlib1g-dev libexpat1-dev

RUN mkdir -p /libuuas/build/
WORKDIR /libuuas/build/

RUN mkdir -p /libuuas/lib/
COPY lib/ /libuuas/lib/

RUN cmake /libuuas/lib/
RUN make -j$(nproc)
RUN make install


#### Rust bindings build image ####
FROM rust:latest AS rustbuild
RUN mkdir -p /libuuas/
WORKDIR /libuuas/

RUN apt-get update -y && apt-get install -y llvm clang

COPY --from=libbuild /usr/local/lib/ /usr/local/lib/
COPY --from=libbuild /usr/local/include/ /usr/local/include/
RUN ldconfig /usr/local/lib/

COPY bindings/rust/ ./build
WORKDIR /libuuas/build/
RUN cargo build --release


#### Python bindings build image ####
FROM python:latest AS pybuild
RUN mkdir -p /libuuas/
WORKDIR /libuuas/

COPY --from=libbuild /usr/local/lib/ /usr/local/lib/
COPY --from=libbuild /usr/local/include/ /usr/local/include/
RUN ldconfig /usr/local/lib/

COPY bindings/python/requirements.txt ./
RUN pip install -r requirements.txt

COPY bindings/python/ ./build
WORKDIR /libuuas/build/
RUN python3 setup.py bdist_wheel
