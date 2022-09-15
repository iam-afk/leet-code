mod p0013;
mod p0030;
mod p0048;
mod p0126;
mod p0200;
mod p0342;
mod p0383;
mod p0387;
mod p0393;
mod p0637;
mod p0804;
mod p0948;
mod p0967;
mod p1329;
mod p1338;
mod p1448;
mod p1457;
mod p1996;
mod p2007;

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

    pub fn from(vec: Vec<Option<i32>>) -> Option<Rc<RefCell<TreeNode>>> {
        Self::node(0, vec.as_slice())
    }

    fn node(index: usize, vec: &[Option<i32>]) -> Option<Rc<RefCell<TreeNode>>> {
        if index < vec.len() {
            if let Some(val) = vec[index] {
                return Some(Rc::new(RefCell::new(TreeNode {
                    val,
                    left: Self::node(index * 2 + 1, vec),
                    right: Self::node(index * 2 + 2, vec),
                })));
            }
        }
        None
    }
}
