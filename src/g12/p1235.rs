use std::collections::BTreeMap;

use crate::Solution;

impl Solution {
    pub fn job_scheduling(start_time: Vec<i32>, end_time: Vec<i32>, profit: Vec<i32>) -> i32 {
        let n = profit.len();
        let mut m = BTreeMap::new();
        for x in &start_time {
            m.insert(*x, 0);
        }
        for x in &end_time {
            m.insert(*x, 0);
        }
        for (i, (_, x)) in m.iter_mut().enumerate() {
            *x = i;
        }
        let mut a: Vec<_> = (0..n)
            .map(|i| {
                (
                    *m.get(&start_time[i]).unwrap(),
                    *m.get(&end_time[i]).unwrap(),
                    profit[i],
                )
            })
            .collect();
        a.sort();
        let mut d = vec![0; m.len()];
        let mut p = 0;
        let mut j = 0usize;
        for i in 0..m.len() {
            d[i] = d[i].max(p);
            while j < a.len() && i == a[j].0 {
                d[a[j].1] = d[a[j].1].max(d[i] + a[j].2);
                j += 1;
            }
            p = d[i];
        }

        d.into_iter().max().unwrap_or(0)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(
            Solution::job_scheduling(vec![1, 2, 3, 3], vec![3, 4, 5, 6], vec![50, 10, 40, 70]),
            120
        );
        assert_eq!(
            Solution::job_scheduling(
                vec![1, 2, 3, 4, 6],
                vec![3, 5, 10, 6, 9],
                vec![20, 20, 100, 70, 60]
            ),
            150
        );
        assert_eq!(
            Solution::job_scheduling(vec![1, 1, 1], vec![2, 3, 4], vec![5, 6, 4]),
            6
        );
    }
}
