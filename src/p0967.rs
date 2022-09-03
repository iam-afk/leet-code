use crate::Solution;

impl Solution {
    pub fn nums_same_consec_diff(n: i32, k: i32) -> Vec<i32> {
        let mut result = Vec::new();
        for d in 1..10 {
            Self::generate(1, d, n, k, &mut result);
        }
        result
    }

    fn generate(i: i32, x: i32, n: i32, k: i32, r: &mut Vec<i32>) {
        if i == n {
            r.push(x);
        } else {
            let d = x % 10;
            if (0..10).contains(&(d - k)) {
                Self::generate(i + 1, x * 10 + d - k, n, k, r)
            }
            if k != 0 && (0..10).contains(&(d + k)) {
                Self::generate(i + 1, x * 10 + d + k, n, k, r);
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::nums_same_consec_diff(3, 7),
            [181, 292, 707, 818, 929]
        );
        assert_eq!(
            Solution::nums_same_consec_diff(2, 1),
            [10, 12, 21, 23, 32, 34, 43, 45, 54, 56, 65, 67, 76, 78, 87, 89, 98]
        );
    }
}
