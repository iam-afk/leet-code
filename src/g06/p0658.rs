use crate::Solution;

impl Solution {
    pub fn find_closest_elements(arr: Vec<i32>, k: i32, x: i32) -> Vec<i32> {
        let mut left = 0;
        let mut right = arr.len();
        while left < right - 1 {
            let middle = left + (right - left) / 2;
            if arr[middle] <= x {
                left = middle;
            } else {
                right = middle;
            }
        }
        let range = 0..arr.len();
        for _ in 0..k {
            if !range.contains(&right) {
                left = left.wrapping_sub(1);
            } else if !range.contains(&left) {
                right += 1;
            } else if x.abs_diff(arr[left]) <= x.abs_diff(arr[right]) {
                left = left.wrapping_sub(1);
            } else {
                right += 1;
            }
        }
        arr[left.wrapping_add(1)..right].to_owned()
    }
}

#[cfg(test)]
mod tests {
    use crate::Solution;

    #[test]
    fn example() {
        assert_eq!(
            Solution::find_closest_elements(vec![1, 2, 3, 4, 5], 4, 3),
            [1, 2, 3, 4]
        );
        assert_eq!(
            Solution::find_closest_elements(vec![1, 2, 3, 4, 5], 4, -1),
            [1, 2, 3, 4]
        );
    }
}
