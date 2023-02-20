use crate::Solution;

impl Solution {
    pub fn add_to_array_form(mut num: Vec<i32>, mut k: i32) -> Vec<i32> {
        num.reverse();
        for x in num.iter_mut() {
            let d = *x + k % 10;
            *x = d % 10;
            k /= 10;
            k += if d > 9 { 1 } else { 0 };
        }
        while k > 0 {
            let d = k % 10;
            num.push(d % 10);
            k /= 10;
            k += if d > 9 { 1 } else { 0 };
        }
        num.reverse();
        num
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            [1, 2, 3, 4].as_slice(),
            Solution::add_to_array_form([1, 2, 0, 0].into(), 34)
        );
        assert_eq!(
            [4, 5, 5].as_slice(),
            Solution::add_to_array_form([2, 7, 4].into(), 181)
        );
        assert_eq!(
            [1, 0, 2, 1].as_slice(),
            Solution::add_to_array_form([2, 1, 5].into(), 806)
        );
    }
}
