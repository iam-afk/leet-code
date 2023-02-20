use std::collections::HashSet;
use std::iter::FromIterator;

use crate::Solution;

impl Solution {
    pub fn unique_occurrences(arr: Vec<i32>) -> bool {
        let mut count = vec![0; 2001];
        for x in arr {
            count[(x + 1000) as usize] += 1;
        }
        let n = count.iter().filter(|&&x| x != 0).count();
        let unique: HashSet<i32> = HashSet::from_iter(count.into_iter().filter(|&x| x != 0));
        unique.len() == n
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert!(Solution::unique_occurrences(vec![1, 2, 2, 1, 1, 3]));
        assert!(!Solution::unique_occurrences(vec![1, 2]));
        assert!(Solution::unique_occurrences(vec![
            -3, 0, 1, -3, 1, 1, 1, -3, 10, 0
        ]));
    }
}
