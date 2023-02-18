use crate::{Solution, TreeNode};

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn invert_tree(mut root: Option<Rc<RefCell<TreeNode>>>) -> Option<Rc<RefCell<TreeNode>>> {
        if let Some(node) = root.as_mut() {
            let mut node = node.borrow_mut();
            let left = Self::invert_tree(node.right.take());
            let right = Self::invert_tree(node.left.take());
            node.left = left;
            node.right = right;
        }
        root
    }
}

#[cfg(test)]
mod tests {
    use crate::tree;

    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            tree![4, 7, 2, 9, 6, 3, 1],
            Solution::invert_tree(tree![4, 2, 7, 1, 3, 6, 9])
        );
        assert_eq!(tree![2, 1, 3], Solution::invert_tree(tree![2, 3, 1]));
        assert_eq!(tree![], Solution::invert_tree(tree![]));
    }
}
