use crate::Solution;

impl Solution {
    pub fn is_toeplitz_matrix(matrix: Vec<Vec<i32>>) -> bool {
        let m = matrix.len();
        let n = matrix.last().expect("at least one row").len();
        for i in 0..m {
            for j in 0..n.min(m - i) {
                if matrix[i + j][j] != matrix[i][0] {
                    return false;
                }
            }
        }
        for j in 1..n {
            for i in 0..m.min(n - j) {
                if matrix[i][j + i] != matrix[0][j] {
                    return false;
                }
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
        assert!(Solution::is_toeplitz_matrix(vec![
            vec![1, 2, 3, 4],
            vec![5, 1, 2, 3],
            vec![9, 5, 1, 2]
        ]));
        assert!(!Solution::is_toeplitz_matrix(vec![vec![1, 2], vec![2, 2]]));
    }
}
