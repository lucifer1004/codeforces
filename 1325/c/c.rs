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
    let n = params[0] as usize;
    let mut adj: Vec<Vec<usize>> = vec![vec![];n];
    let mut num = vec![-1; n - 1];
    let mut curr = 0;
    for i in 0..n - 1 {
        let params = read_ints();
        let u = params[0] as usize;
        let v = params[1] as usize;
        adj[u-1].push(i);
        adj[v-1].push(i);
    }
    for i in 0..n {
        if adj[i].len() >= 3 {
            for j in 0..3 {
                num[adj[i][j]] = curr;
                curr += 1;
            }
            break;
        }
    }
    let mut ans = String::new();
    for i in 0..n-1 {
        if num[i] == -1 {
            num[i] = curr;
            curr += 1;
        }
        ans += &format!("{}\n", num[i]);
    }
    println!("{}", ans);
}