use crate::Solution;

impl Solution {
    pub fn num_squares(n: i32) -> i32 {
        let mut d = vec![i32::max_value(); n as usize + 1];
        d[0] = 0;
        for i in 0..n as usize {
            let mut k = 1;
            while i + k * k <= n as usize {
                d[i + k * k] = (d[i] + 1).min(d[i + k * k]);
                k += 1
            }
        }
        d[n as usize]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::num_squares(12), 3);
        assert_eq!(Solution::num_squares(13), 2);
    }
}
