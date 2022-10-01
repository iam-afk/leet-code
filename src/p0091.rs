use crate::Solution;

impl Solution {
    pub fn num_decodings(s: String) -> i32 {
        let mut d = vec![0i32; s.len() + 1];
        d[0] = 1;
        let mut p = b'.';
        for (i, &x) in s.as_bytes().into_iter().rev().enumerate() {
            if x > b'0' {
                d[i + 1] += d[i];
                if x == b'1' && i > 0 {
                    d[i + 1] += d[i - 1];
                }
                if x == b'2' && i > 0 && p <= b'6' {
                    d[i + 1] += d[i - 1];
                }
            }
            p = x;
        }
        d[s.len()]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::num_decodings("12".into()), 2);
        assert_eq!(Solution::num_decodings("226".into()), 3);
        assert_eq!(Solution::num_decodings("06".into()), 0);
    }

    #[test]
    fn test() {
        assert_eq!(Solution::num_decodings("207".into()), 1);
    }
}
