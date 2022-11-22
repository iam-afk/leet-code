mod p0012;
mod p0013;
mod p0016;
mod p0026;
mod p0030;
mod p0038;
mod p0048;
mod p0049;
mod p0091;
mod p0112;
mod p0113;
mod p0126;
mod p0151;
mod p0200;
mod p0212;
mod p0219;
mod p0222;
mod p0223;
mod p0224;
mod p0263;
mod p0279;
mod p0295;
mod p0342;
mod p0345;
mod p0374;
mod p0383;
mod p0387;
mod p0393;
mod p0433;
mod p0557;
mod p0587;
mod p0622;
mod p0623;
mod p0637;
mod p0653;
mod p0658;
mod p0692;
mod p0718;
mod p0732;
mod p0766;
mod p0804;
mod p0835;
mod p0899;
mod p0901;
mod p0947;
mod p0948;
mod p0967;
mod p0976;
mod p0981;
mod p0985;
mod p0990;
mod p1047;
mod p1155;
mod p1293;
mod p1323;
mod p1328;
mod p1329;
mod p1338;
mod p1448;
mod p1457;
mod p1544;
mod p1578;
mod p1662;
mod p1680;
mod p1926;
mod p1996;
mod p2007;
mod p2095;

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
