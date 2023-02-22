use crate::Solution;

impl Solution {
    pub fn ship_within_days(weights: Vec<i32>, days: i32) -> i32 {
        let mut least_weight = weights.iter().max().unwrap().clone();
        loop {
            let mut d = 0;
            let mut day_weight = least_weight;
            for &weight in weights.iter() {
                if day_weight + weight > least_weight {
                    d += 1;
                    day_weight = weight;
                } else {
                    day_weight += weight;
                }
            }
            if d <= days {
                break;
            }
            least_weight += 1;
        }
        least_weight
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
