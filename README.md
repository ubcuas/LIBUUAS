# LIBUUAS
`LIBUUAS` is our multi-language library used to consolidate common functionality.

## Dependencies
**Docker:**
- Docker

**Local:**
- Rust + Cargo
- Python + Pip
- CMake
- GCC or Clang
- Make

## Building the Library
The libraries and binding docker images can all be built using the following make commands:
```
make docker
```
The libraries and bindings can all be built locally using this command:
```
make build
```
To install them locally (rather than use the docker images):
```
make install
```
A full list of make commands can be shown:
```
make list
```

## Usage
Since the library has no executable of it's own, it's only usage is to act as a dependency for other services. By building the docker images, docker will tag them as the latest. Any docker based service can then be rebuilt, and will use the newly built docker images as the base.

Some services will require `libuuas` to be installed locally when they are built locally. Use the install commands above to the same effect.

## Troubleshooting
Contact `Eric Mikulin`
