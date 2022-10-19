use std::collections::{BTreeMap, HashMap};

use crate::Solution;

impl Solution {
    pub fn top_k_frequent(words: Vec<String>, mut k: i32) -> Vec<String> {
        let mut counts = HashMap::new();
        for word in &words {
            counts.entry(word).and_modify(|c| *c += 1).or_insert(1);
        }
        let mut frequency: BTreeMap<i32, Vec<&String>> = BTreeMap::new();
        for (word, count) in counts {
            frequency.entry(count).or_default().push(word);
        }
        let mut result = Vec::new();
        for (_, words) in frequency.iter_mut().rev() {
            words.sort();
            for word in words {
                result.push(word.clone());
                k -= 1;
                if k == 0 {
                    return result;
                }
            }
        }
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::top_k_frequent(
                vec![
                    "i".into(),
                    "love".into(),
                    "leetcode".into(),
                    "i".into(),
                    "love".into(),
                    "coding".into()
                ],
                2
            ),
            ["i", "love"]
        );
        assert_eq!(
            Solution::top_k_frequent(
                vec![
                    "the".into(),
                    "day".into(),
                    "is".into(),
                    "sunny".into(),
                    "the".into(),
                    "the".into(),
                    "the".into(),
                    "sunny".into(),
                    "is".into(),
                    "is".into()
                ],
                4
            ),
            ["the", "is", "sunny", "day"]
        )
    }
}
