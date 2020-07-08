## Libuuas build image
FROM debian:latest AS libbuild
RUN mkdir -p /libuuas/
WORKDIR /libuuas/

RUN apt-get update -y && apt-get install -y build-essential git wget libssl-dev
RUN bash -c "wget https://github.com/Kitware/CMake/releases/download/v3.17.3/cmake-3.17.3.tar.gz && \
             tar -xzf cmake-3.17.3.tar.gz && \
             cd cmake-3.17.3 && \
             ./bootstrap && \
             make -j$(nproc) && make install"

RUN mkdir -p /libuuas/build/
WORKDIR /libuuas/build/

COPY lib/ /libuuas/lib/
RUN cmake /libuuas/lib/ && make -j$(nproc) && make install


## Rust bindings build image
FROM rust:latest AS rustbuild
RUN mkdir -p /libuuas
WORKDIR /libuuas

RUN apt-get update -y && apt-get install -y llvm clang
COPY --from=libbuild /usr/local/lib/ /usr/local/lib/
COPY --from=libbuild /usr/local/include/ /usr/local/include/

COPY bindings/rust/ ./build
WORKDIR /libuuas/build/
RUN cargo build --release
