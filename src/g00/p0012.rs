use crate::Solution;

impl Solution {
    pub fn int_to_roman(mut num: i32) -> String {
        let mut r = [b'I', b'V', b'X', b'L', b'C', b'D', b'M', b'_', b'_'].windows(3);
        let mut v = Vec::with_capacity(8);
        while num > 0 {
            let d = num % 10;
            match (r.next(), d) {
                (Some(_), 0) => {}
                (Some(&[one, _, _]), 1..=3) => {
                    for _ in 0..d {
                        v.push(one);
                    }
                }
                (Some(&[one, five, _]), 4) => {
                    v.push(five);
                    v.push(one);
                }
                (Some(&[_, five, _]), 5) => {
                    v.push(five);
                }
                (Some(&[one, five, _]), 5..=8) => {
                    for _ in 5..d {
                        v.push(one);
                    }
                    v.push(five);
                }
                (Some(&[one, _, ten]), 9) => {
                    v.push(ten);
                    v.push(one);
                }
                _ => unreachable!(),
            }
            r.next();
            num /= 10;
        }

        v.reverse();
        String::from_utf8(v).unwrap()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::int_to_roman(3), "III");
        assert_eq!(Solution::int_to_roman(58), "LVIII");
        assert_eq!(Solution::int_to_roman(1994), "MCMXCIV");
    }
}
