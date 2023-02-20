use crate::Solution;

impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        let x = 2 * num_rows as usize - 2;
        if x == 0 {
            return s;
        }
        let s = s.as_bytes();
        let mut t = vec![];
        for i in 0..num_rows as usize {
            let mut j = i;
            let mid = i > 0 && 2 * i != x;
            while j < s.len() {
                t.push(s[j]);
                if mid && j + x - 2 * i < s.len() {
                    t.push(s[j + x - 2 * i]);
                }
                j += x;
            }
        }
        unsafe { String::from_utf8_unchecked(t) }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            "PAHNAPLSIIGYIR",
            Solution::convert("PAYPALISHIRING".into(), 3)
        );
        assert_eq!(
            "PINALSIGYAHRPI",
            Solution::convert("PAYPALISHIRING".into(), 4)
        );
        assert_eq!("A", Solution::convert("A".into(), 1));
    }
}
