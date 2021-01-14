macro_rules! input {
    (source = $s:expr, $($r:tt)*) => {
        let mut iter = $s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
    ($($r:tt)*) => {
        let s = {
            use std::io::Read;
            let mut s = String::new();
            std::io::stdin().read_to_string(&mut s).unwrap();
            s
        };
        let mut iter = s.split_whitespace();
        input_inner!{iter, $($r)*}
    };
}

macro_rules! input_inner {
    ($iter:expr) => {};
    ($iter:expr, ) => {};

    ($iter:expr, $var:ident : $t:tt $($r:tt)*) => {
        let $var = read_value!($iter, $t);
        input_inner!{$iter $($r)*}
    };
}

macro_rules! read_value {
    ($iter:expr, ( $($t:tt),* )) => {
        ( $(read_value!($iter, $t)),* )
    };

    ($iter:expr, [ $t:tt ; $len:expr ]) => {
        (0..$len).map(|_| read_value!($iter, $t)).collect::<Vec<_>>()
    };

    ($iter:expr, chars) => {
        read_value!($iter, String).chars().collect::<Vec<char>>()
    };

    ($iter:expr, usize1) => {
        read_value!($iter, usize) - 1
    };

    ($iter:expr, $t:ty) => {
        $iter.next().unwrap().parse::<$t>().expect("Parse error")
    };
}

fn dfs(u: usize, color: &mut Vec<usize>, adj: &Vec<Vec<usize>>) {
    let mut count = 0;
    for v in adj[u].clone() {
        if color[v] == color[u] {
            count += 1;
        }
    }

    // Since we can reduce the number of conflicts by 1 or 2 each time,
    // we can always make a valid solution after no more than N iterations.
    if count > 1 {
        color[u] = 1 - color[u];
        for v in adj[u].clone() {
            if color[v] == color[u] {
                dfs(v, color, adj);
            }
        }
    }
}

fn main() {
    input! {
        n: usize,
        m: usize,
        edges: [(usize, usize); m],
    }

    let mut adj: Vec<Vec<usize>> = vec![vec![]; n + 1];
    for (u, v) in edges {
        adj[u].push(v);
        adj[v].push(u);
    }

    let mut color = vec![0; n + 1];
    
    for i in 0..n {
        dfs(i + 1, &mut color, &adj);
    }

    println!("{}", color[1..=n].into_iter().map(|x| x.to_string()).collect::<Vec<String>>().join(""));
}
