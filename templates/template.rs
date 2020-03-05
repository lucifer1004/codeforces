use std::io;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    return line;
}

fn read_ints() -> Vec<i32> {
    let line = read_line();
    return line.trim().split(" ")
        .filter(|&s| s.len() > 0)
        .map(|s| {
            s.parse::<i32>().unwrap()
        }).collect();
}

fn main() {
    let params = read_ints();
    let n = params[0];
    let k = params[1];
    let a = read_ints();
    println!("{} {}", n, k);
    println!("{:?}", a);
}