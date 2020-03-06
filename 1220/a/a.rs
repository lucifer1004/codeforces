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
    read_ints();
    let s = read_line();
    let mut z = 0;
    for c in s.chars() {
        if c == 'z' {
            z+=1;
        }
    }
    let ones = (s.len() - z * 4) / 3;
    let mut ans = String::new();
    for _ in 0..ones {
        ans.push('1');
        ans.push(' ');
    }
    for _ in 0..z {
        ans.push('0');
        ans.push(' ');
    }
    println!("{}", ans);
}