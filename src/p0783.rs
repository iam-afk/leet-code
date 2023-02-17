use std::{cell::RefCell, rc::Rc};

use crate::{Solution, TreeNode};

impl Solution {
    pub fn min_diff_in_bst(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut min_diff = i32::MAX;
        Self::min_diff_in_subbst(root, -100_000, &mut min_diff);
        min_diff
    }

    fn min_diff_in_subbst(
        root: Option<Rc<RefCell<TreeNode>>>,
        prev: i32,
        min_diff: &mut i32,
    ) -> i32 {
        if let Some(node) = root {
            let mut node = node.borrow_mut();
            let last = Self::min_diff_in_subbst(node.left.take(), prev, min_diff);
            *min_diff = (node.val - last).abs().min(*min_diff);
            let last = Self::min_diff_in_subbst(node.right.take(), node.val, min_diff);
            last
        } else {
            prev
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
