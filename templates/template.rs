use std::io;

fn main() {
    let mut size = String::new();
    io::stdin().read_line(&mut size).unwrap();
    let size: Vec<&str> = size.split(" ").collect();
    let a: u64 = size[0].trim().parse().unwrap();
    let b: u64 = size[1].trim().parse().unwrap();
    
    print!("{} {}", a, b);
}