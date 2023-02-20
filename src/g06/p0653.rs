use crate::Solution;
use crate::TreeNode;

use std::cell::RefCell;
use std::rc::Rc;

impl Solution {
    pub fn find_target(root: Option<Rc<RefCell<TreeNode>>>, k: i32) -> bool {
        let mut lefts = Vec::new();
        Self::push_left(&mut lefts, root.clone());
        let mut rights = Vec::new();
        Self::push_right(&mut rights, root.clone());
        let mut left = Self::next_left(&mut lefts);
        let mut right = Self::next_right(&mut rights);
        while left < right {
            match (left + right).cmp(&k) {
                std::cmp::Ordering::Less => left = Self::next_left(&mut lefts),
                std::cmp::Ordering::Equal => return true,
                std::cmp::Ordering::Greater => right = Self::next_right(&mut rights),
            }
        }
        false
    }

    fn push_left(stack: &mut Vec<Rc<RefCell<TreeNode>>>, root: Option<Rc<RefCell<TreeNode>>>) {
        let mut current = root;
        while let Some(node) = current {
            stack.push(node.clone());
            current = node.borrow().left.clone();
        }
    }

    fn next_left(stack: &mut Vec<Rc<RefCell<TreeNode>>>) -> i32 {
        let node = stack.pop().unwrap();
        let node = node.borrow();
        Self::push_left(stack, node.right.clone());
        node.val
    }

    fn push_right(stack: &mut Vec<Rc<RefCell<TreeNode>>>, root: Option<Rc<RefCell<TreeNode>>>) {
        let mut current = root;
        while let Some(node) = current {
            stack.push(node.clone());
            current = node.borrow().right.clone();
        }
    }

    fn next_right(stack: &mut Vec<Rc<RefCell<TreeNode>>>) -> i32 {
        let node = stack.pop().unwrap();
        let node = node.borrow();
        Self::push_right(stack, node.left.clone());
        node.val
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert!(Solution::find_target(
            crate::tree![5, 3, 6, 2, 4, null, 7],
            9
        ));
        assert!(!Solution::find_target(
            crate::tree![5, 3, 6, 2, 4, null, 7],
            28
        ));
    }
}
