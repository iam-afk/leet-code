use crate::Solution;

impl Solution {
    pub fn single_non_duplicate(nums: Vec<i32>) -> i32 {
        let mut l = 0usize;
        let mut r = nums.len();
        while l < r - 1 {
            let m = l + (r - l) / 2;
            if nums[m] == nums[m + 1] {
                if m & 1 == 0 {
                    l = m + 2;
                } else {
                    r = m;
                }
            } else if m > 0 && nums[m - 1] == nums[m] {
                if m & 1 == 0 {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                return nums[m];
            }
        }
        nums[l]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            2,
            Solution::single_non_duplicate(vec![1, 1, 2, 3, 3, 4, 4, 8, 8])
        );
        assert_eq!(
            10,
            Solution::single_non_duplicate(vec![3, 3, 7, 7, 10, 11, 11])
        );
    }

    #[test]
    fn text() {
        assert_eq!(1, Solution::single_non_duplicate(vec![1]));
        assert_eq!(1, Solution::single_non_duplicate(vec![1, 2, 2]));
        assert_eq!(2, Solution::single_non_duplicate(vec![1, 1, 2]));
    }
}
