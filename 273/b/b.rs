use std::collections::HashMap;

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

fn main() {
    input! {
        n: usize,
        a: [u64; n],
        b: [u64; n],
        m: u64,
    }

    let mut mp = HashMap::<u64, u64>::new();
    for num in a.clone() {
        let entry = mp.entry(num).or_insert(0);
        *entry += 1;
    }
    
    let mut ans = 1u64;
    let mut same = 0;
    for i in 0..n {
        let entry = mp.entry(b[i]).or_insert(0);
        *entry += 1;
        if b[i] == a[i] {
            same += 1;
        }
    }
    
    for (_key, value) in mp.into_iter() {
        for j in 2..=value {
            if same > 0 && j % 2 == 0 {
                ans = ans * (j / 2) % m;
                same -= 1;
            } else {
                ans = ans * j % m;
            }      
        }
    }
    
    println!("{}", ans);
}
