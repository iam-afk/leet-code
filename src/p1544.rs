use crate::Solution;

impl Solution {
    pub fn make_good(s: String) -> String {
        let mut vec = Vec::new();
        for cur in s.into_bytes() {
            if let Some(top) = vec.last() {
                if top ^ cur == 0b100000 {
                    vec.pop();
                    continue;
                }
            }
            vec.push(cur);
        }
        String::from_utf8(vec).unwrap()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::make_good("leEeetcode".into()), "leetcode");
        assert_eq!(Solution::make_good("abBAcC".into()), "");
        assert_eq!(Solution::make_good("s".into()), "s");
    }
}
