use crate::ListNode;
use crate::Solution;

impl Solution {
    pub fn delete_middle(head: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut stack = Vec::new();

        let mut slow = head.as_ref().map(Box::as_ref);
        let mut fast = head.as_ref().map(Box::as_ref);
        while let Some(node) = fast {
            fast = node.next.as_ref().map(Box::as_ref);
            if let Some(node) = fast {
                if let Some(current) = slow {
                    stack.push(current.val);
                    slow = current.next.as_ref().map(Box::as_ref);
                }
                fast = node.next.as_ref().map(Box::as_ref);
            }
        }
        if let Some(node) = slow {
            slow = node.next.as_ref().map(Box::as_ref);
            while let Some(node) = slow {
                stack.push(node.val);
                slow = node.next.as_ref().map(Box::as_ref);
            }
        }

        let mut result = None;
        while let Some(val) = stack.pop() {
            result = Some(Box::new(ListNode { next: result, val }));
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
            Solution::delete_middle(crate::list![1, 3, 4, 7, 1, 2, 6]),
            crate::list![1, 3, 4, 1, 2, 6]
        );
        assert_eq!(
            Solution::delete_middle(crate::list![1, 2, 3, 4]),
            crate::list![1, 2, 4]
        );
        assert_eq!(Solution::delete_middle(crate::list![2, 1]), crate::list![2])
    }

    #[test]
    fn test() {
        assert_eq!(Solution::delete_middle(crate::list![1]), crate::list![]);
        assert_eq!(Solution::delete_middle(crate::list![]), crate::list![]);
    }
}
