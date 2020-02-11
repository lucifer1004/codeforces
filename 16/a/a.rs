use std::io;

fn main() {
  let mut size = String::new();
  io::stdin().read_line(&mut size).unwrap();
  let size: Vec<&str> = size.split(" ").collect();
  let n: usize = size[0].trim().parse().unwrap();
  let m: usize = size[1].trim().parse().unwrap();
  let mut flag = vec!["".to_owned(); n];
  for i in 0..n {
    io::stdin().read_line(&mut flag[i]).unwrap();
  }
  let mut last_line = flag[0].as_bytes()[0];
  let mut valid = true;
  for i in 0..n {
    let first_symbol = flag[i].as_bytes()[0];
    if i > 0 && first_symbol == last_line {
      valid = false;
      break;
    }
    for j in 1..m {
      if flag[i].as_bytes()[j] != first_symbol {
        valid = false;
        break;
      }
    }
    last_line = flag[i].as_bytes()[0];
    if !valid {
      break;
    }
  }
  match valid {
    true => print!("YES"),
    false => print!("NO"),
  }
}