use std::io;

fn read_line() -> String {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    return line.trim().to_string();
}

fn read_ints() -> Vec<usize> {
    let line = read_line();
    return line
        .split(" ")
        .filter(|&s| s.len() > 0)
        .map(|s| s.parse::<usize>().unwrap())
        .collect();
}

fn main() {
    let params = read_ints();
    assert_eq!(params.len(), 1);
    let n = params[0];
    let mut a: Vec<usize> = vec![];
    for _ in 0..n {
        let params = read_ints();
        assert_eq!(params.len(), 2);
        let u = params[0];
        let v = params[1];
        a.push(u);
        a.push(v);
    }
    for k in (0..21).rev() {
        let mask = (1 << k) - 1;
        let mut adj: Vec<Vec<usize>> = vec![vec![]; 1 << k];
        let mut edges = vec![0usize; n << 1];
        for i in 0..n {
            let l = i << 1;
            let r = l | 1;
            let u = a[l] & mask;
            let v = a[r] & mask;
            edges[l] = u;
            edges[r] = v;
            adj[u].push(l);
            adj[v].push(r);
        }
        let mut ok = true;
        for i in 0..1 << k {
            if adj[i].len() % 2 == 1 {
                ok = false;
                break;
            }
        }
        if !ok {
            continue;
        }
        let mut st: Vec<usize> = vec![];
        let mut ans: Vec<usize> = vec![];
        let mut vis = vec![false; n << 1];
        st.push(1);
        vis[0] = true;
        vis[1] = true;
        while !st.is_empty() {
            let curr = st.last().unwrap().clone();
            let pair = curr ^ 1;
            let u = edges[curr];
            if adj[u].is_empty() {
                st.pop();
                ans.push(curr);
                ans.push(pair);
            } else {
                while let Some(l) = adj[u].pop() {
                    if vis[l] {
                        continue;
                    }
                    let r = l ^ 1;
                    vis[r] = true;
                    st.push(r);
                    break;
                }
            }
        }
        if ans.len() == (n << 1) {
            println!("{}", k);
            println!(
                "{}",
                ans.iter()
                    .map(|x| (x + 1).to_string())
                    .collect::<Vec<String>>()
                    .join(" ")
            );
            break;
        }
    }
}
