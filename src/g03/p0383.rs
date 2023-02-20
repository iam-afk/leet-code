use crate::Solution;

impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut c = [0; 26];
        for b in magazine.bytes() {
            c[(b - b'a') as usize] += 1;
        }
        for b in ransom_note.bytes() {
            let x = &mut c[(b - b'a') as usize];
            if *x == 0 {
                return false;
            }
            *x -= 1;
        }
        true
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::can_construct("a".into(), "b".into()), false);
        assert_eq!(Solution::can_construct("aa".into(), "ab".into()), false);
        assert_eq!(Solution::can_construct("aa".into(), "aab".into()), true);
    }
}
