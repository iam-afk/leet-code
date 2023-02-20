use crate::Solution;

impl Solution {
    pub fn total_fruit(fruits: Vec<i32>) -> i32 {
        let mut r = 0;

        let (mut t1, mut t2) = (-1, -1);
        let (mut s1, mut s2) = (0, 0);
        let mut s = 0;
        for i in 0..fruits.len() {
            let x = fruits[i];
            if t1 < 0 || t1 == x {
                t1 = x;
                s1 = i;
            } else if t2 < 0 || t2 == x {
                t2 = x;
                s2 = i;
            } else {
                r = r.max(i as i32 - s as i32);
                if s1 < s2 {
                    s = s1 + 1;
                    t1 = x;
                    s1 = i;
                } else {
                    s = s2 + 1;
                    t2 = x;
                    s2 = i;
                }
            }
        }
        r = r.max(fruits.len() as i32 - s as i32);

        r
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(3, Solution::total_fruit([1, 2, 1].into()));
        assert_eq!(3, Solution::total_fruit([0, 1, 2, 2].into()));
        assert_eq!(4, Solution::total_fruit([1, 2, 3, 2, 2].into()));
    }

    #[test]
    fn test() {
        assert_eq!(5, Solution::total_fruit([0, 1, 6, 6, 4, 4, 6].into()));
    }
}
