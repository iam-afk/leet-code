use std::{cell::RefCell, rc::Rc};

use crate::{Solution, TreeNode};

impl Solution {
    pub fn min_diff_in_bst(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        Self::min_diff_in_subbst(root, &mut None).unwrap()
    }

    fn min_diff_in_subbst(
        root: Option<Rc<RefCell<TreeNode>>>,
        prev: &mut Option<i32>,
    ) -> Option<i32> {
        if let Some(node) = root {
            let mut node = node.borrow_mut();

            let mut min_diff = Self::min_diff_in_subbst(node.left.take(), prev);
            if let Some(prev_val) = prev {
                let diff = (node.val - *prev_val).abs();
                min_diff = min_diff.map(|v| v.min(diff)).or(Some(diff));
            }
            prev.replace(node.val);
            if let Some(diff) = Self::min_diff_in_subbst(node.right.take(), prev) {
                min_diff = min_diff.map(|v| v.min(diff)).or(Some(diff));
            }
            min_diff
        } else {
            None
        }
    }
}

#[cfg(test)]
mod tests {
    use crate::tree;

    use super::*;

    #[test]
    fn example() {
        assert_eq!(1, Solution::min_diff_in_bst(tree![4, 2, 6, 1, 3]));
        assert_eq!(
            1,
            Solution::min_diff_in_bst(tree![1, 0, 48, null, null, 12, 49])
        );
    }

    #[test]
    fn test() {
        assert_eq!(
            6,
            Solution::min_diff_in_bst(tree![27, null, 34, null, 58, 50, null, 44])
        );
    }
}
