use crate::Solution;

impl Solution {
    pub fn remove_duplicates_2(s: String) -> String {
        let mut s = s.into_bytes();
        let mut len = 0usize;
        for j in 0..s.len() {
            if len > 0 && s[len - 1] == s[j] {
                len -= 1;
            } else {
                s.swap(len, j);
                len += 1;
            }
        }
        s.resize(len, 0u8);
        String::from_utf8(s).unwrap()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::remove_duplicates_2("abbaca".into()), "ca");
        assert_eq!(Solution::remove_duplicates_2("azxxzy".into()), "ay");
    }
}
