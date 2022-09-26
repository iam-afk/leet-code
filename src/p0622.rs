struct MyCircularQueue {
    inner: Vec<i32>,
    len: usize,
    head: usize,
    tail: usize,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
#[allow(dead_code)]
impl MyCircularQueue {
    fn new(k: i32) -> Self {
        Self {
            inner: vec![-1; k as usize],
            len: 0,
            head: 0,
            tail: 0,
        }
    }

    fn en_queue(&mut self, value: i32) -> bool {
        if self.len < self.inner.len() {
            self.inner[self.tail] = value;
            self.tail = (self.tail + 1) % self.inner.len();
            self.len += 1;
            true
        } else {
            false
        }
    }

    fn de_queue(&mut self) -> bool {
        if self.len > 0 {
            self.head = (self.head + 1) % self.inner.len();
            self.len -= 1;
            true
        } else {
            false
        }
    }

    fn front(&self) -> i32 {
        if self.len > 0 {
            self.inner[self.head]
        } else {
            -1
        }
    }

    fn rear(&self) -> i32 {
        if self.len > 0 {
            self.inner[(self.tail + self.inner.len() - 1) % self.inner.len()]
        } else {
            -1
        }
    }

    fn is_empty(&self) -> bool {
        self.len == 0
    }

    fn is_full(&self) -> bool {
        self.len == self.inner.len()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        crate::assert_design! {
            obj: MyCircularQueue;
            [new, en_queue, en_queue, en_queue, en_queue, rear, is_full, de_queue, en_queue, rear];
            [[3], [1], [2], [3], [4], [], [], [], [4], []];
            [null, true, true, true, false, 3, true, true, true, 4];
        }
        assert_eq!(obj.front(), 2);
        assert!(!obj.is_empty())
    }
}
