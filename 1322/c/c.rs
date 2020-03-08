use std::io;
use std::collections::HashMap;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    return line.trim().to_string();
}

fn read_ints() -> Vec<i64> {
    let line = read_line();
    return line.split(" ")
        .filter(|&s| s.len() > 0)
        .map(|s| {
            s.parse::<i64>().unwrap()
        }).collect();
}

fn gcd(a: i64, b: i64) -> i64 {
    return if b == 0 {
        a
    } else {
        gcd(b, a % b)
    };
}

fn encode(a: &Vec<i64>) -> i64 {
    let mut code: i64 = 0;
    let mut level: i64 = 1;
    let modulo: i64 = 100000000003;
    for i in a {
        code = (code + i * level) % modulo;
        level = level * 500009 % modulo;
    }
    return code;
}

fn main() {
    let params = read_ints();
    let t = params[0];
    let mut ans = String::new();
    for _ in 0..t {
        let params = read_ints();
        let n = params[0];
        let m = params[1];
        let c = read_ints();
        let mut adj = vec![Vec::<i64>::new(); (n + 1) as usize];
        for _ in 0..m {
            let params = read_ints();
            let u = params[0];
            let v = params[1];
            adj[v as usize].push(u);
        }
        let mut groups = HashMap::<i64, Vec<i64>>::new();
        for i in 1..(n + 1) as usize {
            adj[i].sort();
            let code = encode(&adj[i]);
            groups.entry(code).or_insert(Vec::new()).push(i as i64);
        }
        let mut result: i64 = 0;
        for group in groups {
            if group.0 == 0 {
                continue;
            }
            let mut sum: i64 = 0;
            for i in group.1 {
                sum += c[(i - 1) as usize];
            }
            result = gcd(result, sum);
        }
        ans += result.to_string().as_ref();
        ans += "\n";
        read_line();
    }
    println!("{}", ans);
}