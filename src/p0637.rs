use crate::Solution;
use crate::TreeNode;

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn average_of_levels(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<f64> {
        let mut result = vec![];
        let mut level = vec![root.clone()];
        while !level.is_empty() {
            let count = level.len();
            let mut sum = 0i64;
            let mut next_level = vec![];
            for node in level.into_iter().flatten() {
                let node = node.borrow();
                sum += node.val as i64;
                if node.left.is_some() {
                    next_level.push(node.left.clone());
                }
                if node.right.is_some() {
                    next_level.push(node.right.clone());
                }
            }
            result.push(sum as f64 / count as f64);
            level = next_level;
        }
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::average_of_levels(crate::tree![3, 9, 20, null, null, 15, 7]),
            [3.00000, 14.50000, 11.00000]
        );
        assert_eq!(
            Solution::average_of_levels(crate::tree![3, 9, 20, 15, 7]),
            [3.00000, 14.50000, 11.00000]
        );
    }
}
