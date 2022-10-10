use crate::Solution;

impl Solution {
    pub fn break_palindrome(palindrome: String) -> String {
        let mut palindrome = palindrome.into_bytes();
        let half_len = palindrome.len() / 2;
        if palindrome.len() == 1 {
            return String::new();
        }
        if let Some(first_not_a) = palindrome[..half_len].iter_mut().find(|&&mut c| c != b'a') {
            *first_not_a = b'a';
        } else if let Some(last) = palindrome.last_mut() {
            *last = b'b';
        }
        unsafe { String::from_utf8_unchecked(palindrome) }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::break_palindrome("abccba".into()), "aaccba");
        assert_eq!(Solution::break_palindrome("a".into()), "");
    }

    #[test]
    fn test() {
        assert_eq!(Solution::break_palindrome("aba".into()), "abb");
    }
}
