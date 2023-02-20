use crate::Solution;
use crate::TreeNode;

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn has_path_sum(root: Option<Rc<RefCell<TreeNode>>>, mut target_sum: i32) -> bool {
        if let Some(node) = root {
            let node = node.borrow();
            target_sum -= node.val;
            if node.left.is_none() && node.right.is_none() {
                return target_sum == 0;
            }
            return Self::has_path_sum(node.left.clone(), target_sum)
                || Self::has_path_sum(node.right.clone(), target_sum);
        }
        false
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert!(Solution::has_path_sum(
            crate::tree![5, 4, 8, 11, null, 13, 4, 7, 2, null, null, null, 1],
            22
        ));
        assert!(!Solution::has_path_sum(crate::tree![1, 2, 3], 5));
        assert!(!Solution::has_path_sum(crate::tree![], 0));
    }
}
