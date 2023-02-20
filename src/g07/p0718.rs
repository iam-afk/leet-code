use std::mem::swap;

use crate::Solution;

impl Solution {
    pub fn find_length(mut nums1: Vec<i32>, mut nums2: Vec<i32>) -> i32 {
        if nums1.len() < nums2.len() {
            swap(&mut nums1, &mut nums2);
        }
        let mut prev = vec![0; nums2.len()];
        let mut cur = Vec::with_capacity(nums2.len());
        let mut result = 0;
        for x in nums1 {
            for (j, &y) in nums2.iter().enumerate() {
                let v = if x == y {
                    1 + if j > 0 { prev[j - 1] } else { 0 }
                } else {
                    0
                };
                result = result.max(v);
                cur.push(v);
            }
            swap(&mut prev, &mut cur);
            cur.clear();
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
            Solution::find_length(vec![1, 2, 3, 2, 1], vec![3, 2, 1, 4, 7]),
            3
        );
        assert_eq!(
            Solution::find_length(vec![0, 0, 0, 0, 0], vec![0, 0, 0, 0, 0]),
            5
        );
    }
}
