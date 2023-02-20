#![allow(dead_code)]
use std::collections::BTreeMap;

#[derive(Default)]
struct MyCalendarThree {
    events: BTreeMap<i32, i32>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MyCalendarThree {
    fn new() -> Self {
        Default::default()
    }

    fn book(&mut self, start: i32, end: i32) -> i32 {
        self.events
            .entry(start)
            .and_modify(|e| *e += 1)
            .or_insert(1);
        self.events.entry(end).and_modify(|e| *e -= 1).or_insert(-1);
        self.events
            .iter()
            .scan(0, |c, (_, &d)| {
                *c += d;
                Some(*c)
            })
            .max()
            .unwrap_or(0)
    }
}

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * let obj = MyCalendarThree::new();
 * let ret_1: i32 = obj.book(start, end);
 */
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        crate::assert_design! {
            obj: MyCalendarThree;
            [new, book, book, book, book, book, book];
            [[], [10, 20], [50, 60], [10, 40], [5, 15], [5, 10], [25, 55]];
            [null, 1, 1, 2, 3, 3, 3];
        }
    }

    #[test]
    fn test() {
        crate::assert_design! {
            obj: MyCalendarThree;
            [new, book, book];
            [[], [1, 4], [1, 4]];
            [null, 1, 2];
        }
        crate::assert_design! {
            obj: MyCalendarThree;
            [new, book, book, book, book, book, book, book, book, book, book, book, book, book, book, book, book, book, book, book, book, book, book, book, book, book, book, book, book, book, book];
            [[], [47, 50], [1, 10], [27, 36], [40, 47], [20, 27], [15, 23], [10, 18], [27, 36], [17, 25], [8, 17], [24, 33], [23, 28], [21, 27], [47, 50], [14, 21], [26, 32], [16, 21], [2, 7], [24, 33], [6, 13], [44, 50], [33, 39], [30, 36], [6, 15], [21, 27], [49, 50], [38, 45], [4, 12], [46, 50], [13, 21]];
            [null, 1, 1, 1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7];
        }
    }
}
