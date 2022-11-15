use crate::Solution;
use crate::TreeNode;

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn count_nodes(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        if let Some(node) = root {
            let node = node.borrow();
            let mut left_depth = 0;
            let mut left = node.left.clone();
            while let Some(node) = left {
                left_depth += 1;
                left = node.borrow().left.clone();
            }
            let mut right_depth = 0;
            let mut right = node.right.clone();
            while let Some(node) = right {
                right_depth += 1;
                right = node.borrow().right.clone();
            }
            if left_depth == right_depth {
                (2 << left_depth) - 1
            } else {
                1 + Self::count_nodes(node.left.clone()) + Self::count_nodes(node.right.clone())
            }
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
        assert_eq!(Solution::count_nodes(crate::tree![1, 2, 3, 4, 5, 6]), 6);
        assert_eq!(Solution::count_nodes(crate::tree![]), 0);
        assert_eq!(Solution::count_nodes(crate::tree![1]), 1);
    }
}
