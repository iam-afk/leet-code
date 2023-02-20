use crate::Solution;

impl Solution {
    pub fn gcd_of_strings(str1: String, str2: String) -> String {
        if String::new() + &str1 + &str2 != String::new() + &str2 + &str1 {
            return String::new();
        }
        let (mut a, mut b) = (str1.len().max(str2.len()), str1.len().min(str2.len()));
        while b > 0 {
            let t = a;
            a = b;
            b = t % b;
        }
        String::from_utf8_lossy(&str1.as_bytes()[..a]).to_string()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            "ABC",
            Solution::gcd_of_strings("ABCABC".into(), "ABC".into())
        );
        assert_eq!(
            "AB",
            Solution::gcd_of_strings("ABABAB".into(), "ABAB".into())
        );
        assert_eq!("", Solution::gcd_of_strings("LEET".into(), "CODE".into()));
    }
}
