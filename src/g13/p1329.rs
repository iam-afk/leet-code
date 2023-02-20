use crate::Solution;

impl Solution {
    pub fn diagonal_sort(mut mat: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = mat.len();
        let m = mat.first().expect("at least one row").len();
        let mut buf = vec![0; n.max(m)];
        let mut sort = |i: usize, j: usize| {
            let x = (n - i).min(m - j);
            for k in 0..x {
                buf[k] = mat[i + k][j + k];
            }
            buf[..x].sort();
            for k in 0..x {
                mat[i + k][j + k] = buf[k];
            }
        };

        for i in 0..n - 1 {
            sort(i, 0);
        }
        for j in 1..m - 1 {
            sort(0, j);
        }
        mat
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::diagonal_sort(
                [
                    [3, 3, 1, 1].into(),
                    [2, 2, 1, 2].into(),
                    [1, 1, 1, 2].into()
                ]
                .into()
            ),
            [[1, 1, 1, 1], [1, 2, 2, 2], [1, 2, 3, 3]]
        );
        assert_eq!(
            Solution::diagonal_sort(
                [
                    [11, 25, 66, 1, 69, 7].into(),
                    [23, 55, 17, 45, 15, 52].into(),
                    [75, 31, 36, 44, 58, 8].into(),
                    [22, 27, 33, 25, 68, 4].into(),
                    [84, 28, 14, 11, 5, 50].into()
                ]
                .into()
            ),
            [
                [5, 17, 4, 1, 52, 7],
                [11, 11, 25, 45, 8, 69],
                [14, 23, 25, 44, 58, 15],
                [22, 27, 31, 36, 50, 66],
                [84, 28, 75, 33, 55, 68]
            ]
        );
    }
}
