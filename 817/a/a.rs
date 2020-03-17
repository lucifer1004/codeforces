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
    let x1 = params[0];
    let y1 = params[1];
    let x2 = params[2];
    let y2 = params[3];
    let params = read_ints();
    let a = params[0];
    let b = params[1];
    let dx = x2 - x1;
    let dy = y2 - y1;
    if dx % a != 0 || dy % b != 0 {
        println!("NO");
        return;
    }
    let sx = dx / a;
    let sy = dy / b;
    println!("{}", if (sx - sy) % 2 == 0 { "YES" } else { "NO" });
}