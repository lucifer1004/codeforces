use rand::prelude::*;
use std::cell::RefCell;
use std::fmt::Debug;
use std::rc::Rc;

pub trait InternalData<T> {
    fn merge(this: Self, that: Self) -> Self;

    fn unity() -> Self;

    fn from_val(val: T) -> Self;
}

impl<T> InternalData<T> for () {
    fn merge(_: Self, _: Self) -> Self {
        ()
    }

    fn unity() -> Self {
        ()
    }

    fn from_val(val: T) -> Self {
        ()
    }
}

#[derive(Clone, Debug)]
struct TreapNode<T, P>(Option<Rc<RefCell<TreapData<T, P>>>>);

#[derive(Clone, Debug)]
struct TreapData<T, P> {
    val_: T,
    data_: P,
    size_: usize,
    height_: usize,
    key_: i32,
    left_: TreapNode<T, P>,
    right_: TreapNode<T, P>,
}

impl<T: Clone, P: InternalData<T>> TreapData<T, P> {
    fn new(val: T) -> Self {
        Self {
            val_: val.clone(),
            data_: P::from_val(val),
            size_: 1,
            height_: 1,
            key_: random(),
            left_: TreapNode::new(),
            right_: TreapNode::new(),
        }
    }
}

impl<T, P> TreapNode<T, P> {
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

    fn set_left(&mut self, left: TreapNode<T, P>) {
        match self.0 {
            Some(ref mut t) => t.borrow_mut().left_ = left,
            None => {}
        }
    }

    fn set_right(&mut self, right: TreapNode<T, P>) {
        match self.0 {
            Some(ref mut t) => t.borrow_mut().right_ = right,
            None => {}
        }
    }
}

impl<T, P: Clone + InternalData<T>> TreapNode<T, P> {
    fn data(&self) -> P {
        match self.0 {
            Some(ref t) => t.borrow_mut().data_.clone(),
            None => P::unity(),
        }
    }
}

impl<T: Clone, P: Clone + InternalData<T>> TreapNode<T, P> {
    fn update(&mut self) {
        match self.0 {
            Some(ref mut t) => {
                let mut t = t.borrow_mut();
                t.size_ = t.left_.size() + t.right_.size() + 1;
                t.height_ = t.left_.height().max(t.right_.height()) + 1;
                t.data_ = P::merge(
                    P::merge(t.left_.data(), P::from_val(t.val_.clone())),
                    t.right_.data(),
                );
            }
            None => {}
        }
    }
}

impl<T: Clone + PartialOrd, P: Clone + InternalData<T>> TreapNode<T, P> {
    fn merge(mut a: TreapNode<T, P>, mut b: TreapNode<T, P>) -> Self {
        if a.0.is_none() {
            b
        } else if b.0.is_none() {
            a
        } else if a.key() < b.key() {
            a.set_right(TreapNode::<T, P>::merge(a.right(), b));
            a.update();
            a
        } else {
            b.set_left(TreapNode::<T, P>::merge(a, b.left()));
            b.update();
            b
        }
    }

    fn split(mut a: TreapNode<T, P>, size_threshold: usize) -> (Self, Self) {
        match a.0 {
            Some(_) => {
                if a.left().size() >= size_threshold {
                    let (left, right) = TreapNode::<T, P>::split(a.left(), size_threshold);
                    a.set_left(right);
                    a.update();
                    (left, a)
                } else {
                    let (left, right) =
                        TreapNode::<T, P>::split(a.right(), size_threshold - a.left().size() - 1);
                    a.set_right(left);
                    a.update();
                    (a, right)
                }
            }
            None => (TreapNode::new(), TreapNode::new()),
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
pub struct Treap<T, P> {
    root: TreapNode<T, P>,
}

impl<T, P> Treap<T, P> {
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

impl<T: Clone + PartialOrd, P: Clone + InternalData<T>> Treap<T, P> {
    pub fn get_order(&self, val: T) -> usize {
        self.root.get_order(val)
    }

    pub fn minimum(&mut self) -> Option<T> {
        if self.empty() {
            None
        } else {
            self.get_kth(0)
        }
    }

    pub fn maximum(&mut self) -> Option<T> {
        if self.empty() {
            None
        } else {
            self.get_kth(self.size() - 1)
        }
    }

    pub fn get_kth(&mut self, k: usize) -> Option<T> {
        if k >= self.size() {
            None
        } else {
            let (left, right) = TreapNode::<T, P>::split(self.root.clone(), k);
            let (rleft, rright) = TreapNode::<T, P>::split(right, 1);
            let ans = rleft.val();
            self.root = TreapNode::<T, P>::merge(TreapNode::<T, P>::merge(left, rleft), rright);
            ans
        }
    }

    pub fn get_kth_data(&mut self, k: usize) -> Option<P> {
        if k >= self.size() {
            None
        } else {
            let (left, right) = TreapNode::<T, P>::split(self.root.clone(), k);
            let (rleft, rright) = TreapNode::<T, P>::split(right, 1);
            let ans = P::merge(left.data(), P::from_val(rleft.val().unwrap()));
            self.root = TreapNode::<T, P>::merge(TreapNode::<T, P>::merge(left, rleft), rright);
            Some(ans)
        }
    }

    pub fn insert(&mut self, val: T) {
        let k = self.get_order(val.clone());
        let (left, right) = TreapNode::<T, P>::split(self.root.clone(), k);
        let node = TreapNode(Some(Rc::new(RefCell::new(TreapData::new(val)))));
        self.root = TreapNode::<T, P>::merge(TreapNode::<T, P>::merge(left, node), right)
    }

    pub fn delete(&mut self, val: T) {
        if !self.empty() {
            let k = self.get_order(val.clone());
            if k >= self.size() {
                return;
            }
            if self.get_kth(k).unwrap() == val {
                let (left, right) = TreapNode::<T, P>::split(self.root.clone(), k);
                let (_, rright) = TreapNode::<T, P>::split(right, 1);
                self.root = TreapNode::<T, P>::merge(left, rright)
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_treap() {
        impl InternalData<usize> for usize {
            fn merge(this: usize, that: usize) -> usize {
                this + that
            }

            fn unity() -> usize {
                0
            }

            fn from_val(val: usize) -> usize {
                val
            }
        }

        let mut treap: Treap<usize, usize> = Treap::new();
        let n = 1_000usize;
        for i in 1..=n {
            treap.insert(i);
        }
        assert_eq!(treap.get_kth_data(499), Some(125250));

        for i in (1..=n).step_by(2) {
            treap.delete(i);
        }

        assert_eq!(treap.size(), n / 2);
        assert_eq!(treap.get_kth_data(499), Some(250500));

        assert_eq!(treap.get_kth(1), Some(4));
        assert_eq!(treap.get_kth(100), Some(202));
        assert_eq!(treap.get_kth(500), None);

        assert_eq!(treap.get_order(304), 151);

        assert_eq!(treap.minimum(), Some(2));
        assert_eq!(treap.maximum(), Some(1000));

        assert_eq!(treap.get_kth_data(3), Some(20));
    }
}
