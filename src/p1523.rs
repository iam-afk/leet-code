use super::Solution;

impl Solution {
    pub fn count_odds(low: i32, high: i32) -> i32 {
        (high - low + 1 >> 1) + (high - low + 1 & high & 1)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(3, Solution::count_odds(3, 7));
        assert_eq!(1, Solution::count_odds(8, 10));
    }

    #[test]
    fn test() {
        assert_eq!(1, Solution::count_odds(21, 22));
    }
}
