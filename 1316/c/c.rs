use std::io;

fn work(p: i32) -> i32 {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let line: Vec<&str> = line.split(" ").collect();
    for (i, num_str) in line.iter().enumerate() {
        let num: i32 = num_str.trim().parse().unwrap();
        if num % p != 0 {
            return i as i32;
        }
    }
    return -1;
}

fn main() {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let line: Vec<&str> = line.split(" ").collect();
    let p = line[2].trim().parse().unwrap();
    print!("{}", work(p) + work(p));
}