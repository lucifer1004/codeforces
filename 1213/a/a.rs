use std::io;
use std::cmp::min;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    return line.trim().to_string();
}

fn read_ints() -> Vec<i32> {
    let line = read_line();
    return line.split(" ")
        .filter(|&s| s.len() > 0)
        .map(|s| {
            s.parse::<i32>().unwrap()
        }).collect();
}

fn main() {
    let params = read_ints();
    let n = params[0];
    let a = read_ints();
    let mut even = 0;
    for i in a {
        if i % 2 == 0 {
            even += 1;
        }
    }
    println!("{}", min(even, n - even));
}