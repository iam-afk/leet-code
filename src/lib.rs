mod g00;
mod g01;
mod g02;
mod g03;
mod g04;
mod g05;
mod g06;
mod g07;
mod g08;
mod g09;
mod g10;
mod g11;
mod g12;
mod g13;
mod g14;
mod g15;
mod g16;
mod g19;
mod g20;
mod g22;
mod g23;
mod g24;

pub struct Solution;

use std::cell::RefCell;
use std::rc::Rc;

#[derive(Debug, PartialEq, Eq)]
pub struct TreeNode {
    pub val: i32,
    pub left: Option<Rc<RefCell<TreeNode>>>,
    pub right: Option<Rc<RefCell<TreeNode>>>,
}

impl TreeNode {
    #[inline]
    pub fn new(val: i32) -> Self {
        TreeNode {
            val,
            left: None,
            right: None,
        }
    }
}

#[macro_export]
macro_rules! tree {
    () => {
        None::<Rc<RefCell<TreeNode>>>
    };
    ($($rest:tt)+) => {
        $crate::tree_root!($($rest)*)
    };
}

#[macro_export]
macro_rules! tree_root {
    ($val:expr $(,)?) => {
        Some(Rc::new(RefCell::new(TreeNode::new($val))))
    };
    ($val:expr, $($rest:tt)+) => {{
        let root = Rc::new(RefCell::new(TreeNode::new($val)));
        let mut queue = ::std::collections::VecDeque::new();
        queue.push_back(root.clone());
        $crate::tree_inner!{queue, $($rest)*}
        Some(root)
    }}
}

#[macro_export]
macro_rules! tree_inner {
    ($queue:expr, $left:expr $(,)?) => {
        $crate::tree_inner!($queue, $left, null);
    };
    ($queue:expr, null, null $(,)?) => {
        $queue.pop_front().unwrap();
    };
    ($queue:expr, null, $right:expr $(,)?) => {
        {
            let right = Rc::new(RefCell::new(TreeNode::new($right)));
            let node = $queue.pop_front().unwrap();
            let mut node = node.borrow_mut();
            node.right = Some(right.clone());
            $queue.push_back(right);
        }
    };
    ($queue:expr, $left:expr, null $(,)?) => {
        {
            let left = Rc::new(RefCell::new(TreeNode::new($left)));
            let node = $queue.pop_front().unwrap();
            let mut node = node.borrow_mut();
            node.left = Some(left.clone());
            $queue.push_back(left);
        }
    };
    ($queue:expr, $left:expr, $right:expr $(,)?) => {
        {
            let left = Rc::new(RefCell::new(TreeNode::new($left)));
            let right = Rc::new(RefCell::new(TreeNode::new($right)));
            let node = $queue.pop_front().unwrap();
            let mut node = node.borrow_mut();
            node.left = Some(left.clone());
            node.right = Some(right.clone());
            $queue.push_back(left);
            $queue.push_back(right);
        }
    };
    ($queue:expr, $left:tt, $right:tt, $($rest:tt)+) => {
        $crate::tree_inner!($queue, $left, $right);
        $crate::tree_inner!($queue, $($rest)*)
    };
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn tree_macro() {
        assert_eq!(tree![], None);
        assert_eq!(Some(Rc::new(RefCell::new(TreeNode::new(1)))), tree!(1));
        assert_eq!(Some(Rc::new(RefCell::new(TreeNode::new(1)))), tree! { 1, });
    }
}

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
    pub val: i32,
    pub next: Option<Box<ListNode>>,
}

#[allow(dead_code)]
impl ListNode {
    #[inline]
    fn new(val: i32) -> Self {
        ListNode { next: None, val }
    }
}

#[macro_export]
macro_rules! list {
    () => {
        None
    };
    ($val:expr $(,)?) => {
        Some(Box::new(ListNode::new($val)))
    };
    ($val:expr, $($rest:tt)+) => {
        Some(Box::new(ListNode {
            next: $crate::list!($($rest)*),
            val: $val
        }))
    };
}

#[macro_export]
macro_rules! assert_design {
    ($i:ident : $t:tt; []; []; [] $(;)?) => {};
    ($i:ident : $t:tt; [$m:tt]; [[$($p:tt)*]]; [$r:tt] $(;)?) => {
        $crate::assert_call! { $i: $t; $m($($p)*) => $r }
    };
    ($i:ident : $t:tt; [$m:tt, $($ms:tt)*]; [[$($p:tt)*], $($ps:tt)*]; [$r:tt, $($rs:tt)*] $(;)?) => {
        $crate::assert_call! { $i: $t; $m($($p)*) => $r }
        $crate::assert_design! {
            $i: $t;
            [$($ms)*];
            [$($ps)*];
            [$($rs)*];
        }
    };
}

#[macro_export]
macro_rules! assert_call {
    ($i:ident: $t:tt; new($($p:tt)*) => null) => {
        let mut $i = $t::new($($p)*);
    };
    ($i:ident: $t:tt; $m:tt($($p:tt)*) => null) => {
        $i.$m($($p)*);
    };
    ($i:ident: $t:tt; $m:tt($($p:tt)*) => $r:tt) => {
        assert_eq!($i.$m($($p)*), $r, stringify!($i.$m($($p)*)));
    };
}
