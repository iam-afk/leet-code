use crate::Solution;

impl Solution {
    pub fn largest_perimeter(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable_by(|a, b| b.cmp(a));
        for triple in nums.windows(3) {
            match triple {
                &[a, b, c] if b + c > a => return a + b + c,
                _ => {}
            }
        }
        0
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::largest_perimeter(vec![2, 1, 2]), 5);
        assert_eq!(Solution::largest_perimeter(vec![1, 2, 1]), 0);
    }
}
