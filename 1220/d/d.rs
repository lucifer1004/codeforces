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

fn main() {
    let params = read_ints();
    let n = params[0];
    let a = read_ints();
    let mut groups: HashMap<i64, Vec<i64>> = HashMap::new();
    for i in a {
        let lowbit = i & -i;
        groups.entry(lowbit).or_insert(Vec::<i64>::new()).push(i);
    }
    let mut largest: i64 = -1;
    for i in groups.keys() {
        if largest == -1 || groups[i].len() > groups[&largest].len() {
            largest = *i;
        }
    }
    let mut ans = String::from((n - groups[&largest].len() as i64).to_string() + &"\n".to_string());
    for i in groups.keys() {
        if largest == -1 || groups[i].len() > groups[&largest].len() {
            largest = *i;
        }
    }
    for i in groups.keys() {
        if *i != largest {
            for num in &groups[i] {
                ans += &(num.to_string() + &" ".to_string());
            }
        }
    }
    println!("{}", ans);
}