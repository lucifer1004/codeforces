use std::io;

fn gcd(a: u64, b: u64) -> u64 {
  if a < b {
    return gcd(b, a);
  }
  if b == 0 {
    return a;
  }
  return gcd(b, a % b);
}

fn main() {
  let mut size = String::new();
  io::stdin().read_line(&mut size).unwrap();
  let size: Vec<&str> = size.split(" ").collect();
  let a: u64 = size[0].trim().parse().unwrap();
  let b: u64 = size[1].trim().parse().unwrap();
  let mut x: u64 = size[2].trim().parse().unwrap();
  let mut y: u64 = size[3].trim().parse().unwrap();
  let g = gcd(x, y);
  x /= g;
  y /= g;
  // Case 1: keep b and cut a
  let mut area1 = 0;
  let b1 = b / y * y;
  let a1 = b1 * x / y;
  if b1 > 0 && a1 <= a {
    area1 = b1 * a1;
  }

  // Case 2: keep a and cut b
  let mut area2 = 0;
  let a2 = a / x * x;
  let b2 = a2 * y / x;
  if a2 > 0 && b2 <= b {
    area2 = a2 * b2;
  }

  if area2 > area1 {
    print!("{} {}", a2, b2);
  } else if area1 >= area2 && area1 > 0 {
    print!("{} {}", a1, b1);
  } else {
    print!("{} {}", 0, 0);
  }
}