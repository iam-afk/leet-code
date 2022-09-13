use crate::Solution;

impl Solution {
    pub fn valid_utf8(data: Vec<i32>) -> bool {
        let mut n = 0;
        for x in data {
            n = if n == 0 {
                match x {
                    0b0000_0000..=0b0111_1111 => 0,
                    0b1100_0000..=0b1101_1111 => 1,
                    0b1110_0000..=0b1110_1111 => 2,
                    0b1111_0000..=0b1111_0111 => 3,
                    _ => return false,
                }
            } else {
                match x {
                    0b1000_0000..=0b1011_1111 => n - 1,
                    _ => return false,
                }
            }
        }
        n == 0
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::valid_utf8(vec![197, 130, 1]), true);
        assert_eq!(Solution::valid_utf8(vec![235, 140, 4]), false);
    }

    #[test]
    fn test() {
        assert_eq!(Solution::valid_utf8(vec![237]), false);
    }
}
