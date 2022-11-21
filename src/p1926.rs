use std::collections::VecDeque;

use crate::Solution;

impl Solution {
    pub fn nearest_exit(mut maze: Vec<Vec<char>>, entrance: Vec<i32>) -> i32 {
        let mut que = VecDeque::new();
        let (row, col) = (entrance[0], entrance[1]);
        que.push_back((row, col, 0));
        maze[row as usize][col as usize] = '+';
        while let Some((row, col, step)) = que.pop_front() {
            for (delta_row, delta_col) in [(-1, 0), (0, 1), (1, 0), (0, -1)] {
                let next_row = row + delta_row;
                let next_col = col + delta_col;
                if 0 <= next_row
                    && next_row < maze.len() as i32
                    && 0 <= next_col
                    && next_col < maze[next_row as usize].len() as i32
                    && maze[next_row as usize][next_col as usize] == '.'
                {
                    if next_row == 0
                        || next_col == 0
                        || next_row == maze.len() as i32 - 1
                        || next_col == maze[next_row as usize].len() as i32 - 1
                    {
                        return step + 1;
                    }
                    que.push_back((next_row, next_col, step + 1));
                    maze[next_row as usize][next_col as usize] = '+';
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
            Solution::nearest_exit(
                vec![
                    vec!['+', '+', '.', '+'],
                    vec!['.', '.', '.', '+'],
                    vec!['+', '+', '+', '.']
                ],
                vec![1, 2]
            ),
            1
        );
        assert_eq!(
            Solution::nearest_exit(
                vec![
                    vec!['+', '+', '+'],
                    vec!['.', '.', '.'],
                    vec!['+', '+', '+']
                ],
                vec![1, 0]
            ),
            2
        );
        assert_eq!(
            Solution::nearest_exit(vec![vec!['.', '+'],], vec![0, 0]),
            -1
        );
    }
}
