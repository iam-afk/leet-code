use crate::Solution;

impl Solution {
    pub fn maximum69_number(num: i32) -> i32 {
        num + if num / 1000 == 6 {
            3000
        } else if num / 100 % 10 == 6 {
            300
        } else if num / 10 % 10 == 6 {
            30
        } else if num % 10 == 6 {
            3
        } else {
            0
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::maximum69_number(9669), 9969);
        assert_eq!(Solution::maximum69_number(9996), 9999);
        assert_eq!(Solution::maximum69_number(9999), 9999);
    }
}
