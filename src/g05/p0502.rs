use std::collections::BinaryHeap;

use crate::Solution;

impl Solution {
    pub fn find_maximized_capital(k: i32, mut w: i32, profits: Vec<i32>, capital: Vec<i32>) -> i32 {
        let n = profits.len();
        let mut sorted: Vec<_> = (0..n).collect();
        sorted.sort_unstable_by_key(|&i| capital[i]);
        let mut i = 0usize;
        let mut queue = BinaryHeap::new();
        for _ in 0..k {
            while i < n && capital[sorted[i]] <= w {
                queue.push(profits[sorted[i]]);
                i += 1;
            }
            if let Some(profit) = queue.pop() {
                w += profit;
            } else {
                break;
            }
        }
        w
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::find_maximized_capital(2, 0, vec![1, 2, 3], vec![0, 1, 1]),
            4
        );
        assert_eq!(
            Solution::find_maximized_capital(3, 0, vec![1, 2, 3], vec![0, 1, 2]),
            6
        );
    }
}
