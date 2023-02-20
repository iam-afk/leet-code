use crate::Solution;

impl Solution {
    pub fn sum_subarray_mins(arr: Vec<i32>) -> i32 {
        const M: i32 = 1_000_000_000 + 7;
        let mut r = 0;
        let mut d = 0;
        let mut s: Vec<(i32, i32)> = Vec::new();
        for x in arr {
            let mut k = 0;
            while let Some(&(n, c)) = s.last() {
                if x < n {
                    d -= n * c;
                    if d < 0 {
                        d += M;
                    }
                    k += c;
                    s.pop();
                    continue;
                }
                break;
            }
            match s.last_mut() {
                Some((n, c)) if *n == x => *c += k + 1,
                _ => s.push((x, k + 1)),
            }
            d += x * (k + 1);
            d %= M;
            r += d;
            r %= M;
        }
        r
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::sum_subarray_mins(vec![3, 1, 2, 4]), 17);
        assert_eq!(Solution::sum_subarray_mins(vec![11, 81, 94, 43, 3]), 444);
    }

    #[test]
    fn test() {
        assert_eq!(Solution::sum_subarray_mins(vec![3, 1, 2, 1]), 13);
    }
}
