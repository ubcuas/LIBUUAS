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

# x86-64
Locally, you build the library on x86 by running 

```
make build
```

followed by 

```
make install
```

and that should do the trick for the Rust, Python, and C++ components of the library.

As for building the Docker images, you can run

```
make docker
```

Take a look at the Docker multiarch directives if need be, but you shouldn't have to use them for the purposes of this library when considering the current state of our system. 

# ARMv7 (O-Droid)

Python, because it uses a C++ binding library called cppyy, does not run on ARMv7 since the compilation process is extremely tedious. Also, as of Feb. 2022, no parts of our system need the Python part of Libuuas to run on the O-Droid.

To build and install *only* the Rust and C++ components of the library on ARMv7, you run the following commands:
```
make build-cpp
```

```
make build-rust
```

Then to install,

```
make install-cpp
```

```
make install-rust
```

# Other useful Makefile directives

A full list of make commands can be shown:

```
make list
```

## Running tests
Since the library has no executable as its own, testing requires using a special interactive terminal
to run tests. Or, you can run them with your local system configuration.

Currently, only the Python tests are Dockerized.
Run this command to run Python tests:
```make test-py```

## Usage
Since the library has no executable of it's own, it's only usage is to act as a dependency for other services. By building the docker images, docker will tag them as the latest. Any docker based service can then be rebuilt, and will use the newly built docker images as the base.

Some services will require `libuuas` to be installed locally when they are built locally. Use the install commands above to the same effect.

## Troubleshooting
Contact `Eric Mikulin`
