use crate::Solution;

impl Solution {
    pub fn num_rolls_to_target(n: i32, k: i32, target: i32) -> i32 {
        let k = k as usize;
        let target = target as usize;
        let mut a = vec![0; target + 1];
        a[0] = 1;
        for _ in 0..n {
            let mut b = vec![0; target + 1];
            for (i, s) in a.into_iter().enumerate() {
                for j in 1..=k {
                    if (0..target + 1).contains(&(i + j)) {
                        b[i + j] += s;
                        b[i + j] %= 1_000_000_000 + 7;
                    }
                }
            }
            a = b;
        }
        a[target as usize]
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::num_rolls_to_target(1, 6, 3), 1);
        assert_eq!(Solution::num_rolls_to_target(2, 6, 7), 6);
        assert_eq!(Solution::num_rolls_to_target(30, 30, 500), 222616187);
    }
}
