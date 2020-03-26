use std::io;
use std::cmp::max;

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

const MOD: i64 = 998244353;

fn main() {
    let params = read_ints();
    let n = params[0];
    let k = params[1];
    let m = params[2];
    let mut seg_one = vec![Vec::<(i32, i32)>::new(); k as usize];
    let mut seg_zero = vec![Vec::<(i32, i32)>::new(); k as usize];
    for _ in 0..m as usize {
        let params = read_ints();
        let l = params[0];
        let r = params[1];
        let x = params[2];
        for j in 0..k as usize {
            if ((1 << j) & x as usize) > 0 {
                seg_one[j].push((l, r));
            } else {
                seg_zero[j].push((l, r));
            }
        }
    }
    let mut ans: i64 = 1;
    for i in 0..k as usize {
        let mut one = vec![-1; n as usize + 1];
        for segment in &seg_one[i] {
            one[segment.0 as usize] = max(one[segment.0 as usize], segment.1)
        }
        let mut rightmost = 0;
        let mut must_one = vec![false; n as usize + 1];
        for j in 1..n as usize + 1 {
            rightmost = max(rightmost, one[j]);
            if rightmost >= j as i32 {
                must_one[j] = true;
            }
        }
        let mut f = vec![0; n as usize + 1];
        for segment in &seg_zero[i] {
            f[segment.1 as usize] = max(f[segment.1 as usize], segment.0);
        }
        for j in 2..n as usize + 1 {
            f[j] = max(f[j], f[j - 1]);
        }
        let mut dp = vec![0i64; n as usize + 1];
        let mut sum = vec![0i64; n as usize + 1];
        rightmost = 0;
        for j in 1..n as usize + 1 {
            if !must_one[j] {
                dp[j] = sum[j - 1] + if rightmost == 0 { 1 } else { -sum[rightmost as usize - 1] };
                dp[j] %= MOD;
                if dp[j] < 0 {
                    dp[j] += MOD;
                }
            }
            sum[j] = (sum[j - 1] + dp[j]) % MOD;
            rightmost = max(rightmost, f[j]);
        }
        let mut total = sum[n as usize] + if rightmost == 0 { 1 } else { -sum[rightmost as usize - 1] };
        total %= MOD;
        if total < 0 {
            total += MOD;
        }
        ans = ans * total % MOD;
    }
    println!("{}", ans);
}