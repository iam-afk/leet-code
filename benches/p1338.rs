#![feature(test)]
extern crate test;

use test::Bencher;

use leet_code::Solution;

#[bench]
fn bench(b: &mut Bencher) {
    b.iter(|| {
        let arr = (1..=100_000).collect();
        Solution::min_set_size(arr);
    })
}
