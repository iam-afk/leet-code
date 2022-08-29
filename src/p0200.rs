use crate::Solution;

use std::collections::VecDeque;

impl Solution {
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        let m = grid.len();
        let n = grid.first().expect("at least one row exists").len();
        let mut r = 0;
        let mut queue = VecDeque::with_capacity(m * n);
        for i in 0..m {
            for j in 0..n {
                if grid[i][j] == '1' {
                    queue.push_back((i, j));
                    while let Some((r, c)) = queue.pop_front() {
                        for (r, c) in [
                            (r.wrapping_sub(1), c),
                            (r.wrapping_add(1), c),
                            (r, c.wrapping_sub(1)),
                            (r, c.wrapping_add(1)),
                        ] {
                            if (0..m).contains(&r) && (0..n).contains(&c) && grid[r][c] == '1' {
                                queue.push_back((r, c));
                                grid[r][c] = 'x';
                            }
                        }
                    }
                    r += 1;
                }
            }
        }
        r
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::num_islands(
                [
                    ['1', '1', '1', '1', '0'].into(),
                    ['1', '1', '0', '1', '0'].into(),
                    ['1', '1', '0', '0', '0'].into(),
                    ['0', '0', '0', '0', '0'].into()
                ]
                .into()
            ),
            1
        );
        assert_eq!(
            Solution::num_islands(
                [
                    ['1', '1', '0', '0', '0'].into(),
                    ['1', '1', '0', '0', '0'].into(),
                    ['0', '0', '1', '0', '0'].into(),
                    ['0', '0', '0', '1', '1'].into()
                ]
                .into()
            ),
            3
        );
    }
}
