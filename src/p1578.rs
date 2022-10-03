use std::cmp::min;

use crate::Solution;

impl Solution {
    pub fn min_cost(colors: String, needed_time: Vec<i32>) -> i32 {
        let mut d = vec![[-1; 26 + 1]; colors.len() + 1];
        Self::find(colors.as_bytes(), &needed_time, b'z' + 1, &mut d)
    }

    fn find(colors: &[u8], needed_time: &[i32], last: u8, d: &mut Vec<[i32; 27]>) -> i32 {
        let x = d[colors.len()][(last - b'a') as usize];
        if x >= 0 {
            return x;
        }
        let x = match (colors, needed_time) {
            ([], []) => 0,
            ([c, rest_colors @ ..], [t, rest_time @ ..]) if *c == last => {
                Self::find(rest_colors, rest_time, last, d) + t
            }
            ([c, rest_colors @ ..], [t, rest_time @ ..]) => min(
                Self::find(rest_colors, rest_time, last, d) + t,
                Self::find(rest_colors, rest_time, *c, d),
            ),
            _ => unreachable!(),
        };
        d[colors.len()][(last - b'a') as usize] = x;
        x
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::min_cost("abaac".into(), vec![1, 2, 3, 4, 5]), 3);
        assert_eq!(Solution::min_cost("abc".into(), vec![1, 2, 3]), 0);
        assert_eq!(Solution::min_cost("aabaa".into(), vec![1, 2, 3, 4, 1]), 2);
    }

    #[test]
    fn test() {
        assert_eq!(
            Solution::min_cost("bbbaaa".into(), vec![4, 9, 3, 8, 8, 9]),
            23
        );
    }
}
