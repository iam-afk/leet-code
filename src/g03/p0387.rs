use crate::Solution;

impl Solution {
    pub fn first_uniq_char(s: String) -> i32 {
        let mut c = [0; 26];
        for b in s.as_bytes() {
            c[(b - b'a') as usize] += 1;
        }
        match s
            .into_bytes()
            .into_iter()
            .position(|b| c[(b - b'a') as usize] == 1)
        {
            Some(k) => k as i32,
            None => -1,
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::first_uniq_char("leetcode".into()), 0);
        assert_eq!(Solution::first_uniq_char("loveleetcode".into()), 2);
        assert_eq!(Solution::first_uniq_char("aabb".into()), -1);
    }
}
