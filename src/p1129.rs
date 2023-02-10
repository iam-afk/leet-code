use crate::Solution;

use std::collections::VecDeque;

impl Solution {
    pub fn shortest_alternating_paths(
        n: i32,
        red_edges: Vec<Vec<i32>>,
        blue_edges: Vec<Vec<i32>>,
    ) -> Vec<i32> {
        let mut red = vec![-1; n as usize];
        let mut blue = vec![-1; n as usize];
        red[0] = 0;
        blue[0] = 0;
        enum Color {
            Red,
            Blue,
        }
        let mut queue = VecDeque::new();
        queue.push_back((Color::Red, 0));
        queue.push_back((Color::Blue, 0));
        while let Some((color, v)) = queue.pop_front() {
            match color {
                Color::Red => {
                    let k = red[v as usize];
                    for edge in &blue_edges {
                        let &[a, b] = &edge[..] else { unreachable!() };
                        if v == a && blue[b as usize] < 0 {
                            blue[b as usize] = k + 1;
                            queue.push_back((Color::Blue, b));
                        }
                    }
                }
                Color::Blue => {
                    let k = blue[v as usize];
                    for edge in &red_edges {
                        let &[a, b] = &edge[..] else { unreachable!() };
                        if v == a && red[b as usize] < 0 {
                            red[b as usize] = k + 1;
                            queue.push_back((Color::Red, b));
                        }
                    }
                }
            }
        }

        dbg!(&red, &blue);
        std::iter::zip(red.into_iter(), blue.into_iter())
            .map(|(r, b)| {
                if r < 0 || b < 0 {
                    std::cmp::max(r, b)
                } else {
                    std::cmp::min(r, b)
                }
            })
            .collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            [0, 1, -1].as_slice(),
            Solution::shortest_alternating_paths(3, vec![vec![0, 1], vec![1, 2]], vec![])
        );
        assert_eq!(
            [0, 1, -1].as_slice(),
            Solution::shortest_alternating_paths(3, vec![vec![0, 1]], vec![vec![2, 1]])
        );
    }
}
