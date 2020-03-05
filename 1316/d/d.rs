use std::io;
use std::collections::VecDeque;
use std::process::exit;

fn read_ints() -> Vec<i32> {
    let mut line = String::new();
    io::stdin().read_line(&mut line).unwrap();
    return line.trim().split(" ")
        .filter(|&s| s.len() > 0)
        .map(|s| {
            s.parse::<i32>().unwrap()
        }).collect();
}

#[derive(Debug, Copy, Clone)]
struct Node {
    x: i32,
    y: i32,
    sx: i32,
    sy: i32,
}

fn main() {
    let params = read_ints();
    let n = params[0];
    let mut tx = vec![vec![-1; (n + 1) as usize]; (n + 1) as usize];
    let mut ty = vec![vec![-1; (n + 1) as usize]; (n + 1) as usize];
    let mut s = vec![vec!['S'; (n + 1) as usize]; (n + 1) as usize];
    let mut q: VecDeque<Node> = VecDeque::new();
    let directions = vec![[-1, 0], [0, -1], [0, 1], [1, 0]];
    let symbols = vec!['D', 'R', 'L', 'U'];
    for i in 0..n {
        let iu = i as usize;
        let a = read_ints();
        for j in 0..n {
            let ju = j as usize;
            tx[iu + 1][ju + 1] = a[ju * 2];
            ty[iu + 1][ju + 1] = a[ju * 2 + 1];
            if a[ju * 2] == i + 1 && a[ju * 2 + 1] == j + 1 {
                q.push_back(Node {
                    x: i + 1,
                    y: j + 1,
                    sx: i + 1,
                    sy: j + 1,
                });
                s[iu + 1][ju + 1] = 'X';
            }
        }
    }

    // Handle cells that have a target
    while !q.is_empty() {
        let front = q.front().unwrap().clone();
        q.pop_front();
        for (i, d) in directions.iter().enumerate() {
            let nx = front.x + d[0];
            let ny = front.y + d[1];
            let nxu = nx as usize;
            let nyu = ny as usize;
            if nx <= 0 || nx > n || ny <= 0 || ny > n ||
                tx[nxu][nyu] != front.sx ||
                ty[nxu][nyu] != front.sy ||
                s[nxu][nyu] != 'S' {
                continue;
            }
            s[nxu][nyu] = symbols[i];
            q.push_back(Node {
                x: nx,
                y: ny,
                sx: front.sx,
                sy: front.sy,
            })
        }
    }

    // Handle cells that will loop infinitely
    for i in 1..(n + 1) as usize {
        for j in 1..(n + 1) as usize {
            if tx[i][j] != -1 {
                continue;
            }
            for (k, d) in directions.iter().enumerate() {
                let nx = i as i32 + d[0];
                let ny = j as i32 + d[1];
                let nxu = nx as usize;
                let nyu = ny as usize;
                if nx <= 0 || nx > n || ny <= 0 || ny > n || tx[nxu][nyu] != -1 {
                    continue;
                }
                s[i][j] = symbols[3 - k];
                break;
            }
        }
    }

    for i in 1..(n + 1) as usize {
        for j in 1..(n + 1) as usize {
            if s[i][j] == 'S' {
                println!("INVALID");
                exit(0);
            }
        }
    }
    println!("VALID");
    for i in 1..(n + 1) as usize {
        for j in 1..(n + 1) as usize {
            print!("{}", s[i][j]);
        }
        println!();
    }
}