use crate::Solution;

use std::cmp::Ordering;

trait AbsDiff {
    fn abs_diff(self, other: i32) -> i32;
}

impl AbsDiff for i32 {
    fn abs_diff(self, other: i32) -> i32 {
        (self - other).abs()
    }
}

impl Solution {
    pub fn three_sum_closest(mut nums: Vec<i32>, target: i32) -> i32 {
        nums.sort();
        let mut result = i32::max_value();
        for k in 0..nums.len() - 2 {
            let mut i = k + 1;
            let mut j = nums.len() - 1;
            while i < j {
                let sum = nums[k] + nums[i] + nums[j];
                match sum.cmp(&target) {
                    Ordering::Less => i += 1,
                    Ordering::Equal => return sum,
                    Ordering::Greater => j -= 1,
                }
                if sum.abs_diff(target) < result.abs_diff(target) {
                    result = sum;
                }
            }
        }
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::three_sum_closest(vec![-1, 2, 1, -4], 1), 2);
        assert_eq!(Solution::three_sum_closest(vec![0, 0, 0], 1), 0);
    }
}
