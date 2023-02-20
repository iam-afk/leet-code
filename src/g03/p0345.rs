use crate::Solution;

impl Solution {
    pub fn reverse_vowels(s: String) -> String {
        let mut s = s.into_bytes();
        let mut left = 0usize;
        let mut right = s.len() - 1;
        let is_vowel = |b| b == b'a' || b == b'e' || b == b'i' || b == b'o' || b == b'u';
        while left < right {
            while left < right && !is_vowel(s[left].to_ascii_lowercase()) {
                left += 1;
            }
            while left < right && !is_vowel(s[right].to_ascii_lowercase()) {
                right -= 1;
            }
            if left < right {
                s.swap(left, right);
                left += 1;
                right -= 1;
            }
        }
        String::from_utf8(s).unwrap()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::reverse_vowels("hello".into()), "holle");
        assert_eq!(Solution::reverse_vowels("leetcode".into()), "leotcede");
    }

    #[test]
    fn test() {
        assert_eq!(Solution::reverse_vowels("aA".into()), "Aa");
    }
}
