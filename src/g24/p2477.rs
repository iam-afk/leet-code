use std::collections::BTreeMap;

use crate::Solution;

impl Solution {
    pub fn minimum_fuel_cost(roads: Vec<Vec<i32>>, seats: i32) -> i64 {
        let g: Vec<_> = {
            if roads.is_empty() {
                vec![vec![].into_boxed_slice()]
            } else {
                let mut m: BTreeMap<usize, Vec<usize>> = Default::default();
                for road in roads {
                    let (a, b) = (road[0] as usize, road[1] as usize);
                    m.entry(a).or_default().push(b);
                    m.entry(b).or_default().push(a);
                }
                m.into_values().map(Vec::into_boxed_slice).collect()
            }
        };

        fn dfs(v: usize, p: usize, g: &[Box<[usize]>], seats: i32) -> (i64, i32, i32) {
            let mut liters = 0;
            let mut cars = 1;
            let mut occupied = 1;
            for &u in g[v].iter() {
                if u == p {
                    continue;
                }
                let (l, c, o) = dfs(u, v, g, seats);
                liters += l + c as i64;
                if occupied + o <= seats {
                    occupied += o;
                    cars += c - 1;
                } else {
                    occupied = o - (seats - occupied);
                    cars += c;
                }
            }
            (liters, cars, occupied)
        }

        dfs(0, usize::MAX, &g, seats).0
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            3,
            Solution::minimum_fuel_cost(vec![vec![0, 1], vec![0, 2], vec![0, 3]], 5)
        );
        assert_eq!(
            7,
            Solution::minimum_fuel_cost(
                vec![
                    vec![3, 1],
                    vec![3, 2],
                    vec![1, 0],
                    vec![0, 4],
                    vec![0, 5],
                    vec![4, 6]
                ],
                2
            )
        );
        assert_eq!(0, Solution::minimum_fuel_cost(vec![], 1));
    }
}
