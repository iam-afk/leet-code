use crate::Solution;

impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut rows = vec![vec![false; 10]; 9];
        let mut cols = vec![vec![false; 10]; 9];
        let mut sqrs = vec![vec![false; 10]; 9];
        for (i, row) in board.into_iter().enumerate() {
            for (j, cell) in row.into_iter().enumerate() {
                if cell == '.' {
                    continue;
                }
                let index = cell as usize - b'0' as usize;
                if rows[i][index] {
                    return false;
                };
                if cols[j][index] {
                    return false;
                }
                let square_index = i / 3 * 3 + j / 3;
                if sqrs[square_index][index] {
                    return false;
                }
                rows[i][index] = true;
                cols[j][index] = true;
                sqrs[square_index][index] = true;
            }
        }
        true
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert!(Solution::is_valid_sudoku(vec![
            vec!['5', '3', '.', '.', '7', '.', '.', '.', '.'],
            vec!['6', '.', '.', '1', '9', '5', '.', '.', '.'],
            vec!['.', '9', '8', '.', '.', '.', '.', '6', '.'],
            vec!['8', '.', '.', '.', '6', '.', '.', '.', '3'],
            vec!['4', '.', '.', '8', '.', '3', '.', '.', '1'],
            vec!['7', '.', '.', '.', '2', '.', '.', '.', '6'],
            vec!['.', '6', '.', '.', '.', '.', '2', '8', '.'],
            vec!['.', '.', '.', '4', '1', '9', '.', '.', '5'],
            vec!['.', '.', '.', '.', '8', '.', '.', '7', '9']
        ]));
        assert!(!Solution::is_valid_sudoku(vec![
            vec!['8', '3', '.', '.', '7', '.', '.', '.', '.'],
            vec!['6', '.', '.', '1', '9', '5', '.', '.', '.'],
            vec!['.', '9', '8', '.', '.', '.', '.', '6', '.'],
            vec!['8', '.', '.', '.', '6', '.', '.', '.', '3'],
            vec!['4', '.', '.', '8', '.', '3', '.', '.', '1'],
            vec!['7', '.', '.', '.', '2', '.', '.', '.', '6'],
            vec!['.', '6', '.', '.', '.', '.', '2', '8', '.'],
            vec!['.', '.', '.', '4', '1', '9', '.', '.', '5'],
            vec!['.', '.', '.', '.', '8', '.', '.', '7', '9']
        ]));
    }
}
