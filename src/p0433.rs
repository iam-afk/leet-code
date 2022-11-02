use std::collections::VecDeque;

use crate::Solution;

impl Solution {
    pub fn min_mutation(start: String, end: String, mut bank: Vec<String>) -> i32 {
        let mut queue = VecDeque::new();
        queue.push_back((0, start));
        while let Some((step, gene)) = queue.pop_front() {
            if gene == end {
                return step;
            }
            bank.retain(|other| {
                let mutation = std::iter::zip(gene.bytes(), other.bytes())
                    .filter(|(a, b)| a != b)
                    .count()
                    == 1;
                if mutation {
                    queue.push_back((step + 1, other.clone()));
                }
                !mutation
            })
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
            Solution::min_mutation(
                "AACCGGTT".into(),
                "AACCGGTA".into(),
                vec!["AACCGGTA".into()]
            ),
            1
        );
        assert_eq!(
            Solution::min_mutation(
                "AACCGGTT".into(),
                "AAACGGTA".into(),
                vec!["AACCGGTA".into(), "AACCGCTA".into(), "AAACGGTA".into()]
            ),
            2
        );
        assert_eq!(
            Solution::min_mutation(
                "AAAAACCC".into(),
                "AACCCCCC".into(),
                vec!["AAAACCCC".into(), "AAACCCCC".into(), "AACCCCCC".into()]
            ),
            3
        );
    }
}
