use crate::Solution;

impl Solution {
    pub fn min_cost(colors: String, needed_time: Vec<i32>) -> i32 {
        let colors = colors.as_bytes();
        let mut p = 0u8;
        let mut sum = 0;
        let mut max = 0;
        let mut result = 0;
        for (i, c) in colors.iter().enumerate() {
            if colors[i] != p {
                result += sum - max;
                sum = needed_time[i];
                max = sum;
            } else {
                sum += needed_time[i];
                max = needed_time[i].max(max);
            }
            p = *c;
        }
        result += sum - max;
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::min_cost("abaac".into(), vec![1, 2, 3, 4, 5]), 3);
        assert_eq!(Solution::min_cost("abc".into(), vec![1, 2, 3]), 0);
        assert_eq!(Solution::min_cost("aabaa".into(), vec![1, 2, 3, 4, 1]), 2);
    }

    #[test]
    fn test() {
        assert_eq!(
            Solution::min_cost("bbbaaa".into(), vec![4, 9, 3, 8, 8, 9]),
            23
        );
    }
}
