use crate::Solution;

impl Solution {
    pub fn add_binary(a: String, b: String) -> String {
        let mut a = a.as_bytes();
        let mut b = b.as_bytes();
        let mut c = Vec::with_capacity(Ord::max(a.len(), b.len()) + 1);
        let mut carry = 0;
        loop {
            match (&a, &b) {
                (&[ra @ .., x], &[rb @ .., y]) => {
                    let z = x - b'0' + y - b'0' + carry;
                    c.push((z & 1) + b'0');
                    carry = z >> 1;
                    a = ra;
                    b = rb;
                }
                _ => break,
            }
        }
        let r = if a.is_empty() { b } else { a };
        for x in r.into_iter().rev() {
            let z = x - b'0' + carry;
            c.push((z & 1) + b'0');
            carry = z >> 1;
        }
        if carry > 0 {
            c.push(carry + b'0');
        }
        c.reverse();
        unsafe { String::from_utf8_unchecked(c) }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!("100", Solution::add_binary("11".into(), "1".into()));
        assert_eq!("10101", Solution::add_binary("1010".into(), "1011".into()));
    }
}
