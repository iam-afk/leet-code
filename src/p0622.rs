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

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * let obj = MyCircularQueue::new(k);
 * let ret_1: bool = obj.en_queue(value);
 * let ret_2: bool = obj.de_queue();
 * let ret_3: i32 = obj.front();
 * let ret_4: i32 = obj.rear();
 * let ret_5: bool = obj.is_empty();
 * let ret_6: bool = obj.is_full();
 */
