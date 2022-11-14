use crate::Solution;

impl Solution {
    pub fn remove_stones(stones: Vec<Vec<i32>>) -> i32 {
        let mut stack = Vec::new();
        let mut used = vec![false; stones.len()];
        let mut result = 0;
        for index in 0..stones.len() {
            if used[index] {
                continue;
            }
            stack.push(index);
            let mut count = 0;
            while let Some(index) = stack.pop() {
                if used[index] {
                    continue;
                }
                used[index] = true;
                count += 1;
                for to in 0..stones.len() {
                    if !used[to]
                        && (stones[to][0] == stones[index][0] || stones[to][1] == stones[index][1])
                    {
                        stack.push(to);
                    }
                }
            }
            result += count - 1;
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
            Solution::remove_stones(vec![
                vec![0, 0],
                vec![0, 1],
                vec![1, 0],
                vec![1, 2],
                vec![2, 1],
                vec![2, 2]
            ]),
            5
        );
        assert_eq!(
            Solution::remove_stones(vec![
                vec![0, 0],
                vec![0, 2],
                vec![1, 1],
                vec![2, 0],
                vec![2, 2]
            ]),
            3
        );
        assert_eq!(Solution::remove_stones(vec![vec![0, 0],]), 0);
    }
}
