extern crate bindgen;

use std::env;
use std::path::PathBuf;

fn main() {
    // Generate Rust/C++ ffi
    println!("cargo:rustc-link-lib=uuas");
    println!("cargo:rerun-if-changed=src/wrapper.hpp");

    let bindings = bindgen::Builder::default()
        .header("src/wrapper.hpp")
        .clang_arg("-I/usr/local/include")
        .parse_callbacks(Box::new(bindgen::CargoCallbacks))
        .generate()
        .expect("Unable to generate bindings");

    let out_path = PathBuf::from(env::var("OUT_DIR").unwrap());
    bindings
        .write_to_file(out_path.join("bindings.rs"))
        .expect("Couldn't write bindings!");
}
