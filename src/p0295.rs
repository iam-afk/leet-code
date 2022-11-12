use std::{cmp::Reverse, collections::BinaryHeap};

struct MedianFinder {
    lo: BinaryHeap<i32>,
    hi: BinaryHeap<Reverse<i32>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MedianFinder {
    fn new() -> Self {
        Self {
            lo: BinaryHeap::new(),
            hi: BinaryHeap::new(),
        }
    }

    fn add_num(&mut self, num: i32) {
        self.lo.push(num);
        if let Some(x) = self.lo.pop() {
            self.hi.push(Reverse(x));
        }
        if self.hi.len() > self.lo.len() {
            if let Some(Reverse(x)) = self.hi.pop() {
                self.lo.push(x);
            }
        }
    }

    fn find_median(&mut self) -> f64 {
        if self.lo.len() == self.hi.len() {
            if let (Some(x), Some(Reverse(y))) = (self.lo.peek(), self.hi.peek()) {
                return (x + y) as f64 / 2f64;
            }
        } else if let Some(&x) = self.lo.peek() {
            return x as f64;
        }
        unreachable!()
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * let obj = MedianFinder::new();
 * obj.add_num(num);
 * let ret_2: f64 = obj.find_median();
 */
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        crate::assert_design! {
            obj: MedianFinder;
            [new, add_num, add_num, find_median, add_num, find_median];
            [[], [1], [2], [], [3], []];
            [null, null, null, 1.5, null, 2.0];
        }
    }
}
