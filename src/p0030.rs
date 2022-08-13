use crate::Solution;
use std::collections::BTreeMap;

impl Solution {
    pub fn find_substring(s: String, words: Vec<String>) -> Vec<i32> {
        let n = words.len();
        let m = words.first().expect("words should be not empty").len();
        let mut word_counts = Vec::with_capacity(n);
        let mut word_indicies = BTreeMap::new();
        for word in &words {
            let i = *word_indicies.entry(word.as_bytes()).or_insert_with(|| {
                word_counts.push(0);
                word_counts.len() - 1
            });
            word_counts[i] += 1;
        }
        let mut result = Vec::new();
        let mut current_counts = vec![0; word_counts.len()];
        for (i, window) in s.as_bytes().windows(n * m).enumerate() {
            for chunk in window.chunks(m) {
                if let Some(&i) = word_indicies.get(&chunk) {
                    current_counts[i] += 1;
                    if current_counts[i] > word_counts[i] {
                        break;
                    }
                } else {
                    break;
                }
            }
            if word_counts == current_counts {
                result.push(i as i32);
            }
            for x in &mut current_counts {
                *x = 0;
            }
        }
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        let result = Solution::find_substring(
            "barfoothefoobarman".into(),
            vec!["foo".into(), "bar".into()],
        );
        assert_eq!(result, vec![0, 9]);
    }

    #[test]
    fn test2() {
        let result = Solution::find_substring(
            "wordgoodgoodgoodbestword".into(),
            vec!["word".into(), "good".into(), "best".into(), "word".into()],
        );
        assert_eq!(result, vec![]);
    }

    #[test]
    fn test3() {
        let result = Solution::find_substring(
            "barfoofoobarthefoobarman".into(),
            vec!["bar".into(), "foo".into(), "the".into()],
        );
        assert_eq!(result, vec![6, 9, 12]);
    }
}
