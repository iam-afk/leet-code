use crate::Solution;

impl Solution {
    pub fn shuffle(nums: Vec<i32>, n: i32) -> Vec<i32> {
        let n = n as usize;
        let mut shuffled = Vec::with_capacity(2 * n);
        for i in 0..n {
            shuffled.push(nums[i]);
            shuffled.push(nums[i + n]);
        }
        return shuffled;
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            [2, 3, 5, 4, 1, 7].as_slice(),
            Solution::shuffle([2, 5, 1, 3, 4, 7].to_vec(), 3)
        );
        assert_eq!(
            [1, 4, 2, 3, 3, 2, 4, 1].as_slice(),
            Solution::shuffle([1, 2, 3, 4, 4, 3, 2, 1].to_vec(), 4)
        );
        assert_eq!(
            [1, 2, 1, 2].as_slice(),
            Solution::shuffle([1, 1, 2, 2].to_vec(), 2)
        );
    }
}
