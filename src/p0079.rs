use crate::Solution;

impl Solution {
    pub fn exist(mut board: Vec<Vec<char>>, word: String) -> bool {
        fn find(board: &mut Vec<Vec<char>>, word: &[u8], row: usize, col: usize) -> bool {
            match word {
                [letter] if *letter as char == board[row][col] => true,
                [letter, rest @ ..] if *letter as char == board[row][col] => {
                    board[row][col] = ' ';
                    if row > 0 && find(board, rest, row - 1, col) {
                        return true;
                    }
                    if row < board.len() - 1 && find(board, rest, row + 1, col) {
                        return true;
                    }
                    if col > 0 && find(board, rest, row, col - 1) {
                        return true;
                    }
                    if col < board[row].len() - 1 && find(board, rest, row, col + 1) {
                        return true;
                    }
                    board[row][col] = *letter as char;
                    false
                }
                _ => false,
            }
        }

        for i in 0..board.len() {
            for j in 0..board[i].len() {
                if find(&mut board, word.as_bytes(), i, j) {
                    return true;
                }
            }
        }

        false
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert!(Solution::exist(
            vec![
                vec!['A', 'B', 'C', 'E'],
                vec!['S', 'F', 'C', 'S'],
                vec!['A', 'D', 'E', 'E']
            ],
            "ABCCED".into()
        ));
        assert!(Solution::exist(
            vec![
                vec!['A', 'B', 'C', 'E'],
                vec!['S', 'F', 'C', 'S'],
                vec!['A', 'D', 'E', 'E']
            ],
            "SEE".into()
        ));
        assert!(!Solution::exist(
            vec![
                vec!['A', 'B', 'C', 'E'],
                vec!['S', 'F', 'C', 'S'],
                vec!['A', 'D', 'E', 'E']
            ],
            "ABCB".into()
        ));
    }

    #[test]
    fn test() {
        assert!(Solution::exist(vec![vec!['a']], "a".into()));
    }
}
