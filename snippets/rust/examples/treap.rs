use rust::bbst::treap::*;

fn main() {
    let mut treap: Treap<i32, ()> = Treap::new();
    let n = 100_000;
    for i in 1..=n {
        treap.insert(i);
    }
    println!("{}", treap.height());
    for i in 1..=n {
        treap.delete(i);
    }
    assert!(treap.empty());
}
