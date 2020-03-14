use std::io;

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
    let t = params[0];
    let mut results = String::new();
    for _  in 0..t {
        read_ints();
        let a = read_ints();
        let mut mono: Vec<i32> = Vec::new();
        let mut ans = 0;
        for ai in a {
            while !mono.is_empty() && mono.last().unwrap() > &ai {
                mono.pop();
                ans += 1;
            }
            mono.push(ai);
        }
        results += &format!("{}\n", ans);
    }
    print!("{}", results);
}