use crate::Solution;

impl Solution {
    pub fn reverse_words(s: String) -> String {
        let mut result = String::with_capacity(s.len());
        let mut words = s.split_whitespace().rev();
        if let Some(last) = words.next() {
            result.push_str(last);
            for word in words {
                result.push(' ');
                result.push_str(word);
            }
        }
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::reverse_words("the sky is blue".into()),
            "blue is sky the"
        );
        assert_eq!(
            Solution::reverse_words("  hello world  ".into()),
            "world hello"
        );
        assert_eq!(
            Solution::reverse_words("a good   example".into()),
            "example good a"
        );
    }
}
