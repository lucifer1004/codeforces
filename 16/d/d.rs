use std::io;

fn main() {
  let mut len = String::new();
  io::stdin().read_line(&mut len).unwrap();
  let n = len.trim().parse().unwrap();
  let mut last = -1;
  let mut day = 1;
  let mut count = 1;
  for _i in 0..n {
    let mut curr = String::new();
    io::stdin().read_line(&mut curr).unwrap();
    let mut hour: i32 = (&curr[1..3]).parse().unwrap();
    let mut minute: i32 = (&curr[4..6]).parse().unwrap();
    if &curr[7..8] == "p" && hour != 12 {
      hour += 12;
    }
    if &curr[7..8] == "a" && hour == 12 {
      hour -= 12;
    }
    minute += hour * 60;
    if minute < last {
      count = 1;
      day += 1;
    } else if minute == last {
      count += 1;
      if count > 10 {
        count = 1;
        day += 1;
      }
    } else {
      count = 1;
    }
    last = minute;
  }
  print!("{}", day);
}