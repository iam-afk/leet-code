use std::str::FromStr;

use crate::Solution;

impl Solution {
    pub fn count_and_say(n: i32) -> String {
        let mut s = vec![b'1'];
        for _ in 1..n {
            let mut c = *s.first().unwrap();
            let mut k = 0;
            let mut t = Vec::with_capacity(2 * s.len());
            for x in s {
                if x != c {
                    t.push(k + b'0');
                    t.push(c);
                    c = x;
                    k = 0;
                }
                k += 1;
            }
            t.push(k + b'0');
            t.push(c);
            s = t;
        }
        String::from_utf8(s).unwrap()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::count_and_say(1), "1");
        assert_eq!(Solution::count_and_say(4), "1211");
    }
}
