use std::io;
use std::cmp::min;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    return line.trim().to_string();
}

fn main() {
    let line = read_line();
    let mut lo = 'z';
    let mut ans = String::new();
    for c in line.chars() {
        if lo < c {
            ans += "Ann\n";
        } else {
            ans += "Mike\n";
        }
        lo = min(lo, c);
    }
    print!("{}", ans);
}