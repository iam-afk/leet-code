use std::cmp::min;

use crate::Solution;

impl Solution {
    pub fn max_distance(mut grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        let md = 2 * n as i32 + 1;
        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 1 {
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = md;
                    grid[i][j] = min(
                        grid[i][j],
                        min(
                            if i > 0 { grid[i - 1][j] + 1 } else { md },
                            if j > 0 { grid[i][j - 1] + 1 } else { md },
                        ),
                    )
                }
            }
        }
        let mut r = 0;
        for i in (0..n).rev() {
            for j in (0..n).rev() {
                grid[i][j] = min(
                    grid[i][j],
                    min(
                        if i < n - 1 { grid[i + 1][j] + 1 } else { md },
                        if j < n - 1 { grid[i][j + 1] + 1 } else { md },
                    ),
                );
                r = r.max(grid[i][j]);
            }
        }
        if r == 0 || r == md {
            -1
        } else {
            r
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            2,
            Solution::max_distance(vec![[1, 0, 1].into(), [0, 0, 0].into(), [1, 0, 1].into()])
        );
        assert_eq!(
            4,
            Solution::max_distance(vec![[1, 0, 0].into(), [0, 0, 0].into(), [0, 0, 0].into()])
        );
    }

    #[test]
    fn test() {
        assert_eq!(
            -1,
            Solution::max_distance(vec![
                [0, 0, 0, 0].into(),
                [0, 0, 0, 0].into(),
                [0, 0, 0, 0].into(),
                [0, 0, 0, 0].into()
            ])
        );
        assert_eq!(
            2,
            Solution::max_distance(vec![
                [0, 0, 1, 1, 1].into(),
                [0, 1, 1, 0, 0].into(),
                [0, 0, 1, 1, 0].into(),
                [1, 0, 0, 0, 0].into(),
                [1, 1, 0, 0, 1].into()
            ])
        );
    }
}
