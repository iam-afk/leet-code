use std::collections::HashSet;

use crate::Solution;

impl Solution {
    pub fn contains_nearby_duplicate(nums: Vec<i32>, k: i32) -> bool {
        let mut window = HashSet::new();
        for (i, x) in nums.iter().enumerate() {
            if window.contains(x) {
                return true;
            }
            window.insert(x);
            if i >= k as usize {
                window.remove(&nums[i - k as usize]);
            }
        }
        false
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert!(Solution::contains_nearby_duplicate(vec![1, 2, 3, 1], 3));
        assert!(Solution::contains_nearby_duplicate(vec![1, 0, 1, 1], 1));
        assert!(!Solution::contains_nearby_duplicate(
            vec![1, 2, 3, 1, 2, 3],
            2
        ));
    }
}
