use std::io;

fn work(p: i32) -> i32 {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    let line: Vec<i32> = line.split(" ").map(|s| {
        s.trim().parse::<i32>().unwrap()
    }).collect();
    for (i, num) in line.iter().enumerate() {
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