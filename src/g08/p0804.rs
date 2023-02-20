use std::collections::HashSet;

use crate::Solution;

impl Solution {
    const TABLE: [(u64, u64); 26] = [
        (1, 2),
        (8, 4),
        (10, 4),
        (4, 3),
        (0, 1),
        (2, 4),
        (6, 3),
        (0, 4),
        (0, 2),
        (7, 4),
        (5, 3),
        (4, 4),
        (3, 2),
        (2, 2),
        (7, 3),
        (6, 4),
        (13, 4),
        (2, 3),
        (0, 3),
        (1, 1),
        (1, 3),
        (1, 4),
        (3, 3),
        (9, 4),
        (11, 4),
        (12, 4),
    ];

    pub fn unique_morse_representations(words: Vec<String>) -> i32 {
        let iter = words.into_iter().map(|word| {
            word.as_bytes()
                .into_iter()
                .map(|b| (b - b'a') as usize)
                .map(|i| Self::TABLE[i])
                .fold(0u64, |r, (x, l)| (r << l) + x)
        });
        let set: HashSet<u64> = HashSet::from_iter(iter);
        set.len() as i32
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::unique_morse_representations(
                ["gin".into(), "zen".into(), "gig".into(), "msg".into()].into()
            ),
            2
        );
        assert_eq!(
            Solution::unique_morse_representations(["a".into()].into()),
            1
        );
    }
}
