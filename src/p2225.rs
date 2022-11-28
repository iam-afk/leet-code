use std::collections::HashMap;

use crate::Solution;

impl Solution {
    pub fn find_winners(matches: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut defeats = HashMap::new();
        for m in matches {
            defeats.entry(m[0]).or_insert(0);
            *defeats.entry(m[1]).or_insert(0) += 1;
        }
        let mut answer = vec![vec![], vec![]];
        for (player, count) in defeats.into_iter() {
            match count {
                0 => answer[0].push(player),
                1 => answer[1].push(player),
                _ => {}
            }
        }
        answer[0].sort();
        answer[1].sort();
        answer
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::find_winners(vec![
                vec![1, 3],
                vec![2, 3],
                vec![3, 6],
                vec![5, 6],
                vec![5, 7],
                vec![4, 5],
                vec![4, 8],
                vec![4, 9],
                vec![10, 4],
                vec![10, 9]
            ]),
            vec![vec![1, 2, 10], vec![4, 5, 7, 8]]
        );
        assert_eq!(
            Solution::find_winners(vec![vec![2, 3], vec![1, 3], vec![5, 4], vec![6, 4]]),
            vec![vec![1, 2, 5, 6], vec![]]
        );
    }
}
