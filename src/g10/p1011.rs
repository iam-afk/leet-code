use crate::Solution;

impl Solution {
    pub fn ship_within_days(weights: Vec<i32>, days: i32) -> i32 {
        let mut left = weights.iter().max().unwrap() - 1;
        let mut right = weights.iter().sum();

        fn enough(max_weight: i32, mut days: i32, weights: &[i32]) -> bool {
            let mut day_weight = max_weight;
            for weight in weights {
                if weight + day_weight > max_weight {
                    if days == 0 {
                        return false;
                    }
                    days -= 1;
                    day_weight = 0;
                }
                day_weight += weight;
            }
            true
        }

        while left < right - 1 {
            let middle = left + (right - left) / 2;
            if enough(middle, days, &weights) {
                right = middle;
            } else {
                left = middle;
            }
        }
        right
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            15,
            Solution::ship_within_days(vec![1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 5)
        );
        assert_eq!(6, Solution::ship_within_days(vec![3, 2, 2, 4, 1, 4], 3));
        assert_eq!(3, Solution::ship_within_days(vec![1, 2, 3, 1, 1], 4));
    }
}
