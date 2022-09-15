use crate::Solution;

impl Solution {
    pub fn find_original_array(mut changed: Vec<i32>) -> Vec<i32> {
        let n = changed.len();
        if n % 2 == 1 {
            return Vec::new();
        }
        changed.sort();
        let mut original = Vec::new();
        let mut i = 0usize;
        let mut j = 0usize;
        for _ in 0..n / 2 {
            if i == n {
                return Vec::new();
            }
            j = j.max(i + 1);
            while j < n && changed[j] != changed[i] * 2 {
                j += 1;
            }
            if j == n {
                return Vec::new();
            }
            original.push(changed[i]);
            i += 1;
            changed[j] = -1;
            j += 1;
            while i < n && changed[i] < 0 {
                i += 1;
            }
        }
        original
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::find_original_array(vec![1, 3, 4, 2, 6, 8]),
            [1, 3, 4]
        );
        assert_eq!(Solution::find_original_array(vec![6, 3, 0, 1]), []);
        assert_eq!(Solution::find_original_array(vec![1]), []);
    }
}
