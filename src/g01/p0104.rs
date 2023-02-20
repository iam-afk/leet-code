use std::{cell::RefCell, rc::Rc};

use crate::{Solution, TreeNode};

impl Solution {
    pub fn max_depth(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if let Some(node) = root {
            let mut node = node.borrow_mut();
            1 + Ord::max(
                Self::max_depth(node.left.take()),
                Self::max_depth(node.right.take()),
            )
        } else {
            0
        }
    }
}

#[cfg(test)]
mod tests {
    use crate::tree;

    use super::*;

    #[test]
    fn example() {
        assert_eq!(3, Solution::max_depth(tree![3, 9, 20, null, null, 15, 7]));
        assert_eq!(2, Solution::max_depth(tree![1, null, 2]));
    }
}
