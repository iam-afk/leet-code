use crate::Solution;

impl Solution {
    pub fn sum_even_after_queries(mut nums: Vec<i32>, queries: Vec<Vec<i32>>) -> Vec<i32> {
        let mut sum = nums.iter().filter(|&&x| x % 2 == 0).sum();
        let mut result = Vec::new();
        for query in queries {
            match &query[..] {
                &[val, index] => {
                    let cur = &mut nums[index as usize];
                    if *cur % 2 == 0 {
                        sum -= *cur;
                    }
                    *cur += val;
                    if *cur % 2 == 0 {
                        sum += *cur;
                    }
                    dbg!(&nums, sum);
                    result.push(sum);
                }
                _ => unreachable!(),
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
            Solution::sum_even_after_queries(
                vec![1, 2, 3, 4],
                vec![[1, 0].into(), [-3, 1].into(), [-4, 0].into(), [2, 3].into()]
            ),
            [8, 6, 2, 4]
        );
        assert_eq!(
            Solution::sum_even_after_queries(vec![1], vec![[4, 0].into()]),
            [0]
        );
    }
}
