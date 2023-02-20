use crate::Solution;

impl Solution {
    pub fn is_ugly(mut n: i32) -> bool {
        if n <= 0 {
            false
        } else {
            for d in [2, 3, 5] {
                while n % d == 0 {
                    n /= d;
                }
            }
            n == 1
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert!(Solution::is_ugly(6));
        assert!(Solution::is_ugly(1));
        assert!(!Solution::is_ugly(14));
    }

    #[test]
    fn test() {
        assert!(!Solution::is_ugly(0));
    }
}
