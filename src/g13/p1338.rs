use crate::Solution;

impl Solution {
    pub fn min_set_size(arr: Vec<i32>) -> i32 {
        let n = arr.len();
        let mut count = vec![0; 100_000 + 1];
        for x in arr {
            count[x as usize] += 1;
        }
        count.sort();
        let mut c = 0;
        for (i, x) in count.into_iter().rev().enumerate() {
            c += x;
            if c >= n / 2 {
                return i as i32 + 1;
            }
        }
        unreachable!()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::min_set_size(vec![3, 3, 3, 3, 5, 5, 5, 2, 2, 7]),
            2
        );
        assert_eq!(Solution::min_set_size(vec![7, 7, 7, 7, 7, 7]), 1);
    }
}
