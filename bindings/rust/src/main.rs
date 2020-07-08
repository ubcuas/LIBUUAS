include!(concat!(env!("OUT_DIR"), "/bindings.rs"));

fn main() {
    let ans = unsafe { double_nums(45, 12) };
    println!("Hello, world! {}", ans);
}
