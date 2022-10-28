use std::collections::HashMap;

use crate::Solution;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut anagrams = HashMap::new();
        for str in strs {
            let count = str.bytes().map(|b| b - b'a').fold([0; 26], |mut count, b| {
                count[b as usize] += 1;
                count
            });
            anagrams.entry(count).or_insert(Vec::new()).push(str);
        }
        anagrams.into_values().collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::group_anagrams(vec![
                "eat".into(),
                "tea".into(),
                "tan".into(),
                "ate".into(),
                "nat".into(),
                "bat".into()
            ]),
            [vec!["bat"], vec!["nat", "tan"], vec!["ate", "eat", "tea"]]
        );
        assert_eq!(Solution::group_anagrams(vec!["".into()]), [vec![""]]);
        assert_eq!(Solution::group_anagrams(vec!["a".into()]), [vec!["a"]]);
    }
}
