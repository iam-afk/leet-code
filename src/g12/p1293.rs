use std::collections::{HashSet, VecDeque};

use crate::Solution;

impl Solution {
    pub fn shortest_path(grid: Vec<Vec<i32>>, k: i32) -> i32 {
        let mut visited = HashSet::new();
        let mut queue = VecDeque::new();
        queue.push_back((0, 0, 0, k));
        visited.insert((0, 0, k));
        while let Some((s, r, c, k)) = queue.pop_front() {
            if r == grid.len() - 1 && c == grid[r].len() - 1 {
                return s;
            }

            if r > 0 {
                if grid[r - 1][c] == 1 {
                    if k > 0 && visited.insert((r - 1, c, k - 1)) {
                        queue.push_back((s + 1, r - 1, c, k - 1));
                    }
                } else if visited.insert((r - 1, c, k)) {
                    queue.push_back((s + 1, r - 1, c, k));
                }
            }
            if r + 1 < grid.len() {
                if grid[r + 1][c] == 1 {
                    if k > 0 && visited.insert((r + 1, c, k - 1)) {
                        queue.push_back((s + 1, r + 1, c, k - 1));
                    }
                } else if visited.insert((r + 1, c, k)) {
                    queue.push_back((s + 1, r + 1, c, k));
                }
            }
            if c > 0 {
                if grid[r][c - 1] == 1 {
                    if k > 0 && visited.insert((r, c - 1, k - 1)) {
                        queue.push_back((s + 1, r, c - 1, k - 1));
                    }
                } else if visited.insert((r, c - 1, k)) {
                    queue.push_back((s + 1, r, c - 1, k));
                }
            }
            if c + 1 < grid[r].len() {
                if grid[r][c + 1] == 1 {
                    if k > 0 && visited.insert((r, c + 1, k - 1)) {
                        queue.push_back((s + 1, r, c + 1, k - 1));
                    }
                } else if visited.insert((r, c + 1, k)) {
                    queue.push_back((s + 1, r, c + 1, k));
                }
            }
        }
        -1
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::shortest_path(
                vec![
                    vec![0, 0, 0],
                    vec![1, 1, 0],
                    vec![0, 0, 0],
                    vec![0, 1, 1],
                    vec![0, 0, 0]
                ],
                1
            ),
            6
        );
        assert_eq!(
            Solution::shortest_path(vec![vec![0, 1, 1], vec![1, 1, 1], vec![1, 0, 0]], 1),
            -1
        );
    }
}
