use std::cell::RefCell;
use std::fmt::Debug;
use std::rc::Rc;
use rand::prelude::*;

#[derive(Clone, Debug)]
struct TreapNode<T>(Option<Rc<RefCell<TreapData<T>>>>);

#[derive(Clone, Debug)]
struct TreapData<T> {
    val_: T,
    size_: usize,
    height_: usize,
    key_: i32,
    left_: TreapNode<T>,
    right_: TreapNode<T>,
}

impl<T> TreapData<T> {
    fn new(val: T) -> Self {
        Self {
            val_: val,
            size_: 1,
            height_: 1,
            key_: random(),
            left_: TreapNode::new(),
            right_: TreapNode::new(),
        }
    }
}

impl<T> TreapNode<T> {
    fn new() -> Self {
        TreapNode(None)
    }

    fn size(&self) -> usize {
        match self.0 {
            Some(ref t) => t.borrow_mut().size_,
            None => 0,
        }
    }

    fn empty(&self) -> bool {
        self.size() == 0
    }

    fn height(&self) -> usize {
        match self.0 {
            Some(ref t) => t.borrow_mut().height_,
            None => 0,
        }
    }

    fn key(&self) -> i32 {
        match self.0 {
            Some(ref t) => t.borrow_mut().key_,
            None => 0,
        }
    }

    fn set_left(&mut self, left: TreapNode<T>) {
        match self.0 {
            Some(ref mut t) => t.borrow_mut().left_ = left,
            None => {}
        }
    }

    fn set_right(&mut self, right: TreapNode<T>) {
        match self.0 {
            Some(ref mut t) => t.borrow_mut().right_ = right,
            None => {}
        }
    }

    fn update(&mut self) {
        match self.0 {
            Some(ref mut t) => {
                let mut t = t.borrow_mut();
                t.size_ = t.left_.size() + t.right_.size() + 1;
                t.height_ = t.left_.height().max(t.right_.height()) + 1;
            },
            None => {}
        }
    }
}

impl<T: Clone + PartialOrd> TreapNode<T> {
    fn merge(mut a: TreapNode<T>, mut b: TreapNode<T>) -> Self {
        if a.0.is_none() {
            b
        } else if b.0.is_none() {
            a
        } else if a.key() < b.key() {
            a.set_right(TreapNode::<T>::merge(a.right(), b));
            a.update();
            a
        } else {
            b.set_left(TreapNode::<T>::merge(a, b.left()));
            b.update();
            b
        }
    }

    fn split(mut a: TreapNode<T>, size_threshold: usize) -> (Self, Self) {
        match a.0 {
            Some(_) => {
                if a.left().size() >= size_threshold {
                    let (left, right) = TreapNode::<T>::split(a.left(), size_threshold);
                    a.set_left(right);
                    a.update();
                    (left, a)
                } else {
                    let (left, right) = TreapNode::<T>::split(a.right(), size_threshold - a.left().size() - 1);
                    a.set_right(left);
                    a.update();
                    (a, right)
                }
            },
            None => (TreapNode::new(), TreapNode::new())
        }
    }

    fn val(&self) -> Option<T> {
        match self.0 {
            Some(ref t) => Some(t.borrow_mut().val_.clone()),
            None => None,
        }
    }

    fn left(&self) -> Self {
        match self.0 {
            Some(ref t) => t.borrow_mut().left_.clone(),
            None => TreapNode(None),
        }
    }

    fn right(&self) -> Self {
        match self.0 {
            Some(ref t) => t.borrow_mut().right_.clone(),
            None => TreapNode(None),
        }
    }

    fn get_order(&self, val: T) -> usize {
        if self.empty() {
            0
        } else if self.val().unwrap() >= val {
            self.left().get_order(val)
        } else {
            self.right().get_order(val) + self.left().size() + 1
        }
    }
}

#[derive(Clone, Debug)]
pub struct Treap<T> {
    root: TreapNode<T>
}

impl<T> Treap<T> {
    pub fn new() -> Self {
        Self {
            root: TreapNode::new(),
        }
    }

    pub fn size(&self) -> usize {
        self.root.size()
    }

    pub fn empty(&self) -> bool {
        self.root.empty()
    }

    pub fn height(&self) -> usize {
        self.root.height()
    }
}

impl<T: Clone + PartialOrd> Treap<T> {
    pub fn get_order(&self, val: T) -> usize {
        self.root.get_order(val)
    }

    pub fn get_kth(&mut self, k: usize) -> Option<T> {
        if k >= self.size() {
            None
        } else {
            let (left, right) = TreapNode::<T>::split(self.root.clone(), k);
            let (rleft, rright) = TreapNode::<T>::split(right, 1);
            let ans = rleft.val();
            self.root = TreapNode::<T>::merge(TreapNode::<T>::merge(left, rleft), rright);
            ans
        }
    }

    pub fn insert(&mut self, val: T) {
        let k = self.get_order(val.clone());
        let (left, right) = TreapNode::<T>::split(self.root.clone(), k);
        let node = TreapNode(Some(Rc::new(RefCell::new(TreapData::new(val)))));
        self.root = TreapNode::<T>::merge(TreapNode::<T>::merge(left, node), right)
    }

    pub fn delete(&mut self, val: T) {
        if !self.empty() {
            let k = self.get_order(val.clone());
            if k >= self.size() {
                return;
            }
            if self.get_kth(k).unwrap() == val {
                let (left, right) = TreapNode::<T>::split(self.root.clone(), k);
                let (_, rright) = TreapNode::<T>::split(right, 1);
                self.root = TreapNode::<T>::merge(left, rright)
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_treap() {
        let mut treap = Treap::new();
        let n = 1_000;
        for i in 1..=n {
            treap.insert(i);
        }
        for i in (1..=n).step_by(2) {
            treap.delete(i);
        }
        assert_eq!(treap.size(), n / 2);
        assert_eq!(treap.get_kth(0), Some(2));
        assert_eq!(treap.get_kth(100), Some(202));
        assert_eq!(treap.get_order(304), 151);
    }
}