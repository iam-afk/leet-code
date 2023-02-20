use crate::Solution;

impl Solution {
    pub fn concatenated_binary(n: i32) -> i32 {
        let mut result = 0u64;
        let mut shift = 1u64;
        let mut power = 2u64;
        for i in 1..=n as u64 {
            if i == power {
                shift += 1;
                power *= 2;
            }
            result <<= shift;
            result += i;
            result %= 1_000_000_000 + 7;
        }
        result as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::concatenated_binary(1), 1);
        assert_eq!(Solution::concatenated_binary(3), 27);
        assert_eq!(Solution::concatenated_binary(12), 505379714);
    }
}
