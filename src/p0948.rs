use crate::Solution;

impl Solution {
    pub fn bag_of_tokens_score(mut tokens: Vec<i32>, mut power: i32) -> i32 {
        if tokens.is_empty() {
            return 0;
        }
        tokens.sort();
        let mut left = 0;
        let mut right = tokens.len();
        let mut score = 0;
        loop {
            let mut index = 0;
            let mut delta = 0;
            while left < right - index && power + delta < tokens[left] && score - index > 0 {
                delta += tokens[right - index - 1];
                index += 1;
            }
            if left >= right - index || power + delta < tokens[left] {
                break;
            }
            power += delta;
            score -= index;
            right -= index;

            power -= tokens[left];
            left += 1;
            score += 1;
        }
        score as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::bag_of_tokens_score(vec![100], 50), 0);
        assert_eq!(Solution::bag_of_tokens_score(vec![100, 200], 150), 1);
        assert_eq!(
            Solution::bag_of_tokens_score(vec![100, 200, 300, 400], 200),
            2
        );
    }

    #[test]
    fn test() {
        assert_eq!(Solution::bag_of_tokens_score(vec![], 85), 0);
    }
}
