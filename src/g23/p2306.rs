use crate::Solution;

use std::collections::HashSet;

impl Solution {
    pub fn distinct_names(ideas: Vec<String>) -> i64 {
        let mut suffixes: [HashSet<&[u8]>; 26] = Default::default();
        for idea in &ideas {
            let idea = idea.as_bytes();
            let index = (idea[0] - b'a') as usize;
            suffixes[index].insert(&idea[1..]);
        }
        let mut r = 0;
        for (i, a) in suffixes.iter().enumerate() {
            for b in suffixes[i + 1..].iter() {
                let x = a.iter().filter(|&&suffix| b.contains(suffix)).count();
                r += 2 * (a.len() - x) * (b.len() - x);
            }
        }
        r as i64
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::fs::read_to_string;

    #[test]
    fn example() {
        assert_eq!(
            6,
            Solution::distinct_names(
                vec![
                    "coffee".into(),
                    "donuts".into(),
                    "time".into(),
                    "toffee".into()
                ]
                .into()
            )
        );
        assert_eq!(
            0,
            Solution::distinct_names(vec!["lack".into(), "back".into(),].into())
        );
    }

    #[test]
    fn test() {
        let ideas: Vec<String> = read_to_string("tests/p2306.in")
            .unwrap()
            .split_whitespace()
            .map(str::to_string)
            .collect();
        assert_eq!(2154522944, Solution::distinct_names(ideas));
    }
}
