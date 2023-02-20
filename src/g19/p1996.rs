use crate::Solution;

impl Solution {
    pub fn number_of_weak_characters(mut properties: Vec<Vec<i32>>) -> i32 {
        properties.sort_unstable_by(|a, b| Ord::cmp(&a[0], &b[0]).reverse());
        let mut current_attack = 0;
        let mut group_maximum = 0;
        let mut maximum = 0;
        let mut result = 0;
        for character in properties {
            if current_attack != character[0] {
                group_maximum = maximum;
                current_attack = character[0];
            }
            maximum = maximum.max(character[1]);
            if character[1] < group_maximum {
                result += 1;
            }
        }
        result
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::number_of_weak_characters(vec![vec![5, 5], vec![6, 3], vec![3, 6]]),
            0
        );
        assert_eq!(
            Solution::number_of_weak_characters(vec![vec![2, 2], vec![3, 3]]),
            1
        );
        assert_eq!(
            Solution::number_of_weak_characters(vec![vec![1, 5], vec![10, 4], vec![4, 3]]),
            1
        );
    }
}
