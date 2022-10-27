use crate::Solution;

impl Solution {
    pub fn largest_overlap(img1: Vec<Vec<i32>>, img2: Vec<Vec<i32>>) -> i32 {
        let n = img1.len();
        let mut max_overlap = 0;
        for di in 0..n {
            for dj in 0..n {
                let mut overlap = 0;
                for i in 0..n - di {
                    for j in 0..n - dj {
                        if img1[i][j] == 1 && img1[i][j] == img2[i + di][j + dj] {
                            overlap += 1;
                        }
                    }
                }
                max_overlap = max_overlap.max(overlap);
            }
        }
        for di in 0..n {
            for dj in 0..n {
                let mut overlap = 0;
                for i in 0..n - di {
                    for j in n - dj..n {
                        if img1[i][j] == 1 && img1[i][j] == img2[i + di][j + dj - n] {
                            overlap += 1;
                        }
                    }
                }
                max_overlap = max_overlap.max(overlap);
            }
        }
        for di in 0..n {
            for dj in 0..n {
                let mut overlap = 0;
                for i in n - di..n {
                    for j in 0..n - dj {
                        if img1[i][j] == 1 && img1[i][j] == img2[i + di - n][j + dj] {
                            overlap += 1;
                        }
                    }
                }
                max_overlap = max_overlap.max(overlap);
            }
        }
        for di in 0..n {
            for dj in 0..n {
                let mut overlap = 0;
                for i in n - di..n {
                    for j in n - dj..n {
                        if img1[i][j] == 1 && img1[i][j] == img2[i + di - n][j + dj - n] {
                            overlap += 1;
                        }
                    }
                }
                max_overlap = max_overlap.max(overlap);
            }
        }
        max_overlap
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::largest_overlap(
                vec![vec![1, 1, 0], vec![0, 1, 0], vec![0, 1, 0]],
                vec![vec![0, 0, 0], vec![0, 1, 1], vec![0, 0, 1]]
            ),
            3
        );
        assert_eq!(Solution::largest_overlap(vec![vec![1]], vec![vec![1]]), 1);
        assert_eq!(Solution::largest_overlap(vec![vec![0]], vec![vec![0]]), 0);
    }

    #[test]
    fn test() {
        assert_eq!(
            Solution::largest_overlap(
                vec![
                    vec![0, 0, 0, 0, 1],
                    vec![0, 0, 0, 0, 0],
                    vec![0, 0, 0, 0, 0],
                    vec![0, 0, 0, 0, 0],
                    vec![0, 0, 0, 0, 0]
                ],
                vec![
                    vec![0, 0, 0, 0, 0],
                    vec![0, 0, 0, 0, 0],
                    vec![0, 0, 0, 0, 0],
                    vec![0, 0, 0, 0, 0],
                    vec![1, 0, 0, 0, 0]
                ]
            ),
            1
        );
    }
}
