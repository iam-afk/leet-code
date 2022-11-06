use crate::Solution;

impl Solution {
    pub fn orderly_queue(mut s: String, k: i32) -> String {
        match k {
            1 => {
                let n = s.len();
                let mut result = vec![b'z'; n];
                let bytes = unsafe { s.as_bytes_mut() };
                for _ in 0..n - 1 {
                    bytes.rotate_left(1);
                    if bytes < result.as_mut_slice() {
                        result.clear();
                        result.extend_from_slice(bytes);
                    }
                }
                String::from_utf8(result).unwrap()
            }
            _ => {
                unsafe { s.as_bytes_mut() }.sort();
                s
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::orderly_queue("cba".into(), 1), "acb");
        assert_eq!(Solution::orderly_queue("baaca".into(), 3), "aaabc");
    }
}
