use crate::Solution;

impl Solution {
    pub fn reverse_words_2(s: String) -> String {
        let mut v: Vec<u8> = s.into();
        for word in v.as_mut_slice().split_mut(u8::is_ascii_whitespace) {
            word.reverse();
        }
        String::from_utf8(v).unwrap()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::reverse_words_2("Let's take LeetCode contest".into()),
            "s'teL ekat edoCteeL tsetnoc"
        );
        assert_eq!(Solution::reverse_words_2("God Ding".into()), "doG gniD");
    }
}
