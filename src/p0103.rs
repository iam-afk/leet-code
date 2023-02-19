use crate::{Solution, TreeNode};

use std::cell::RefCell;
use std::mem::swap;
use std::rc::Rc;

impl Solution {
    pub fn zigzag_level_order(root: Option<Rc<RefCell<TreeNode>>>) -> Vec<Vec<i32>> {
        let mut order = vec![];
        let mut level = Vec::with_capacity(1000);
        let mut next_level = Vec::with_capacity(1000);
        if let Some(root) = root {
            level.push(root);
        }
        while !level.is_empty() {
            next_level.clear();
            let mut order_level = Vec::with_capacity(level.len());
            for node in level.iter().rev() {
                let mut node = node.borrow_mut();
                order_level.push(node.val);
                if order.len() & 1 == 1 {
                    if let Some(right) = node.right.take() {
                        next_level.push(right);
                    }
                    if let Some(left) = node.left.take() {
                        next_level.push(left);
                    }
                } else {
                    if let Some(left) = node.left.take() {
                        next_level.push(left);
                    }
                    if let Some(right) = node.right.take() {
                        next_level.push(right);
                    }
                }
            }
            order.push(order_level);
            swap(&mut level, &mut next_level);
        }
        order
    }
}

#[cfg(test)]
mod tests {
    use crate::tree;

    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            vec![vec![3], vec![20, 9], vec![15, 7]],
            Solution::zigzag_level_order(tree![3, 9, 20, null, null, 15, 7])
        );
        assert_eq!(vec![vec![1]], Solution::zigzag_level_order(tree![1]));
        assert_eq!(vec![], Solution::zigzag_level_order(tree![]));
    }
}
