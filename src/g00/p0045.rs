use crate::Solution;

impl Solution {
    pub fn jump(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut d = vec![i32::MAX; n];
        d[0] = 0;
        for i in 0..n - 1 {
            for j in 1..=(n - i - 1).min(nums[i] as usize) {
                d[i + j] = d[i + j].min(d[i] + 1);
            }
        }
        d[n - 1]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(2, Solution::jump([2, 3, 1, 1, 4].into()));
        assert_eq!(2, Solution::jump([2, 3, 0, 1, 4].into()));
    }

    #[test]
    fn test() {
        assert_eq!(1, Solution::jump([2, 1].into()));
    }
}
