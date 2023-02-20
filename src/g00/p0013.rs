use crate::Solution;

impl Solution {
    pub fn roman_to_int(s: String) -> i32 {
        let mut number = 0;
        let mut previous = 1_000_000;
        for symbol in s.bytes() {
            let value = Self::symbol_to_value(symbol);
            if value > previous {
                number -= 2 * previous;
            }
            number += value;
            previous = value;
        }
        number
    }

    fn symbol_to_value(symbol: u8) -> i32 {
        match symbol {
            b'I' => 1,
            b'V' => 5,
            b'X' => 10,
            b'L' => 50,
            b'C' => 100,
            b'D' => 500,
            b'M' => 1000,
            _ => unreachable!(),
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::roman_to_int("III".into()), 3);
        assert_eq!(Solution::roman_to_int("LVIII".into()), 58);
        assert_eq!(Solution::roman_to_int("MCMXCIV".into()), 1994);
    }
}
