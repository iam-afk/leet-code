use crate::{Solution, TreeNode};

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn good_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::good_nodes_0(root, i32::MIN)
    }
    fn good_nodes_0(root: Option<Rc<RefCell<TreeNode>>>, maximum: i32) -> i32 {
        if let Some(node) = root {
            let node = node.borrow();
            let current = if node.val >= maximum { 1 } else { 0 };
            current
                + Self::good_nodes_0(node.left.clone(), node.val.max(maximum))
                + Self::good_nodes_0(node.right.clone(), node.val.max(maximum))
        } else {
            0
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::good_nodes(crate::tree![3, 1, 4, 3, null, 1, 5]),
            4
        );
        assert_eq!(Solution::good_nodes(crate::tree![3, 3, null, 4, 2]), 3);
        assert_eq!(Solution::good_nodes(crate::tree![1]), 1);
    }
}
