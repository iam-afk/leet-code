use crate::Solution;

impl Solution {
    pub fn array_strings_are_equal(word1: Vec<String>, word2: Vec<String>) -> bool {
        let mut it1 = word1.iter().flat_map(|s| s.chars());
        let mut it2 = word2.iter().flat_map(|s| s.chars());
        loop {
            match (it1.next(), it2.next()) {
                (None, None) => break true,
                (Some(c1), Some(c2)) if c1 == c2 => continue,
                _ => break false,
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert!(Solution::array_strings_are_equal(
            vec!["ab".into(), "c".into()],
            vec!["a".into(), "bc".into()]
        ));
        assert!(!Solution::array_strings_are_equal(
            vec!["a".into(), "cb".into()],
            vec!["ab".into(), "c".into()]
        ));
        assert!(Solution::array_strings_are_equal(
            vec!["abc".into(), "d".into(), "defg".into()],
            vec!["abcddefg".into()]
        ));
    }
}
