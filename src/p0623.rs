use crate::Solution;
use crate::TreeNode;

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn add_one_row(
        root: Option<Rc<RefCell<TreeNode>>>,
        val: i32,
        depth: i32,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if depth == 1 {
            let mut node = TreeNode::new(val);
            node.left = root;
            return Some(Rc::new(RefCell::new(node)));
        }
        if let Some(root) = root.as_ref() {
            let mut node = root.borrow_mut();
            if depth == 2 {
                let mut left = TreeNode::new(val);
                left.left = node.left.clone();
                node.left = Some(Rc::new(RefCell::new(left)));
                let mut right = TreeNode::new(val);
                right.right = node.right.clone();
                node.right = Some(Rc::new(RefCell::new(right)));
            } else {
                Self::add_one_row(node.left.clone(), val, depth - 1);
                Self::add_one_row(node.right.clone(), val, depth - 1);
            }
        }
        root
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::add_one_row(crate::tree![4, 2, 6, 3, 1, 5], 1, 2),
            crate::tree![4, 1, 1, 2, null, null, 6, 3, 1, 5]
        );
        assert_eq!(
            Solution::add_one_row(crate::tree![4, 2, null, 3, 1], 1, 3),
            crate::tree![4, 2, null, 1, 1, 3, null, null, 1]
        );
    }
}
