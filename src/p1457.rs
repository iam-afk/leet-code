use crate::Solution;
use crate::TreeNode;

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn pseudo_palindromic_paths(root: Option<Rc<RefCell<TreeNode>>>) -> i32 {
        let mut count = [0; 10];
        Self::find_pseudo_palindromic_paths(&root, 0, &mut count)
    }

    fn find_pseudo_palindromic_paths(
        root: &Option<Rc<RefCell<TreeNode>>>,
        len: usize,
        count: &mut [i32],
    ) -> i32 {
        if let Some(root) = root {
            let node = root.borrow();
            count[node.val as usize] += 1;
            let mut result = 0;
            if node.left.is_none() && node.right.is_none() {
                if count.iter().filter(|&n| *n % 2 != 0).count() < 2 {
                    result += 1;
                }
            } else {
                if node.left.is_some() {
                    result += Self::find_pseudo_palindromic_paths(&node.left, len + 1, count);
                }
                if node.right.is_some() {
                    result += Self::find_pseudo_palindromic_paths(&node.right, len + 1, count);
                }
            }
            count[node.val as usize] -= 1;
            return result;
        }
        0
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::pseudo_palindromic_paths(TreeNode::from(vec![
                Some(2),
                Some(3),
                Some(1),
                Some(3),
                Some(1),
                None,
                Some(1),
            ])),
            2
        );
        assert_eq!(
            Solution::pseudo_palindromic_paths(TreeNode::from(vec![
                Some(2),
                Some(1),
                Some(1),
                Some(1),
                Some(3),
                None,
                None,
                None,
                None,
                None,
                Some(1),
            ])),
            1
        );
        assert_eq!(
            Solution::pseudo_palindromic_paths(TreeNode::from(vec![Some(9)])),
            1
        );
    }
}
