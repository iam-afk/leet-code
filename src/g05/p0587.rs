use crate::Solution;

impl Solution {
    pub fn outer_trees(trees: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = trees.len();
        if n <= 3 {
            return trees;
        }

        let mut trees: Vec<(i32, i32)> = trees.into_iter().map(|v| (v[0], v[1])).collect();
        trees.sort_by(|a, b| a.0.cmp(&b.0).then_with(|| a.1.cmp(&b.1)));
        let p1 = trees.first().unwrap();
        let p2 = trees.last().unwrap();

        fn cw(a: &(i32, i32), b: &(i32, i32), c: &(i32, i32)) -> i32 {
            (b.0 - a.0) * (c.1 - b.1) - (b.1 - a.1) * (c.0 - b.0)
        }

        let mut up = vec![p1.clone()];
        let mut down = vec![p1.clone()];
        for p in &trees[1..] {
            if cw(p1, p, p2) <= 0 {
                while up.len() > 1 && cw(&up[up.len() - 2], &up[up.len() - 1], p) > 0 {
                    up.pop();
                }
                up.push(p.clone());
            }
            if cw(p1, p, p2) >= 0 {
                while down.len() > 1 && cw(&down[down.len() - 2], &down[down.len() - 1], p) < 0 {
                    down.pop();
                }
                down.push(p.clone());
            }
        }

        if up != down {
            up.extend_from_slice(&down[1..down.len() - 1]);
        }

        up.into_iter().map(|(x, y)| vec![x, y]).collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::collections::HashSet;
    use std::iter::FromIterator;

    #[test]
    fn example() {
        let result: HashSet<Vec<i32>> = HashSet::from_iter(Solution::outer_trees(vec![
            vec![1, 1],
            vec![2, 2],
            vec![2, 0],
            vec![2, 4],
            vec![3, 3],
            vec![4, 2],
        ]));
        assert_eq!(
            result,
            HashSet::from_iter([vec![1, 1], vec![2, 0], vec![3, 3], vec![2, 4], vec![4, 2]])
        );
        let result: HashSet<Vec<i32>> = HashSet::from_iter(Solution::outer_trees(vec![
            vec![1, 2],
            vec![2, 2],
            vec![4, 2],
        ]));
        assert_eq!(
            result,
            HashSet::from_iter([vec![4, 2], vec![2, 2], vec![1, 2]])
        );
    }
}
