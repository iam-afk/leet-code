use crate::Solution;

impl Solution {
    pub fn is_alien_sorted(words: Vec<String>, order: String) -> bool {
        let mut w = [0usize; 26];
        for (i, x) in order.as_bytes().into_iter().enumerate() {
            w[(x - b'a') as usize] = i;
        }
        words.as_slice().windows(2).all(|x| {
            let (mut b1, mut b2) = (x[0].as_bytes().into_iter(), x[1].as_bytes().into_iter());
            dbg!(x);
            loop {
                match (b1.next(), b2.next()) {
                    (Some(x1), Some(x2)) if x1 == x2 => {}
                    (Some(x1), Some(x2)) => {
                        return w[(x1 - b'a') as usize] < w[(x2 - b'a') as usize]
                    }
                    (Some(_), None) => return false,
                    (None, Some(_) | None) => return true,
                }
            }
        })
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert!(Solution::is_alien_sorted(
            vec!["hello".into(), "leetcode".into()],
            "hlabcdefgijkmnopqrstuvwxyz".into()
        ));
        assert!(!Solution::is_alien_sorted(
            vec!["word".into(), "world".into(), "row".into()],
            "worldabcefghijkmnpqstuvxyz".into()
        ));
        assert!(!Solution::is_alien_sorted(
            vec!["apple".into(), "app".into()],
            "abcdefghijklmnopqrstuvwxyz".into()
        ));
    }
}
