use std::collections::HashMap;

use crate::Solution;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut anagrams = HashMap::new();
        for str in strs {
            let mut key: Vec<_> = str.bytes().collect();
            key.sort();
            anagrams.entry(key).or_insert(Vec::new()).push(str);
        }
        anagrams.into_values().collect()
    }
}

#[cfg(test)]
mod tests {
    use std::collections::BTreeSet;

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
            ])
            .into_iter()
            .map(|v| BTreeSet::from_iter(v))
            .collect::<BTreeSet<BTreeSet<String>>>(),
            [
                vec!["bat".into()],
                vec!["nat".into(), "tan".into()],
                vec!["ate".into(), "eat".into(), "tea".into()]
            ]
            .into_iter()
            .map(|v| { BTreeSet::from_iter(v) })
            .collect::<BTreeSet<BTreeSet<String>>>()
        );
        assert_eq!(Solution::group_anagrams(vec!["".into()]), [vec![""]]);
        assert_eq!(Solution::group_anagrams(vec!["a".into()]), [vec!["a"]]);
    }
}
