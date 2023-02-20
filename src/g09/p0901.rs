struct StockSpanner {
    day: i32,
    stack: Vec<(i32, i32)>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
#[allow(dead_code)]
impl StockSpanner {
    fn new() -> Self {
        Self {
            day: 1,
            stack: Vec::new(),
        }
    }

    fn next(&mut self, price: i32) -> i32 {
        let mut result = self.day;
        while let Some(last) = self.stack.last() {
            if last.0 > price {
                break;
            }
            result = last.1;
            self.stack.pop();
        }
        self.day += 1;
        self.stack.push((price, result));
        self.day - result
    }
}

/**
 * Your StockSpanner object will be instantiated and called as such:
 * let obj = StockSpanner::new();
 * let ret_1: i32 = obj.next(price);
 */
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        crate::assert_design! {
            obj: StockSpanner;
            [new, next, next, next, next, next, next, next];
            [[], [100], [80], [60], [70], [60], [75], [85]];
            [null, 1, 1, 1, 2, 1, 4, 6];
        }
    }
}
