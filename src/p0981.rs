use std::collections::HashMap;

#[derive(Default)]
struct TimeMap {
    data: HashMap<String, Vec<(i32, String)>>,
}

/**
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TimeMap {
    fn new() -> Self {
        Default::default()
    }

    fn set(&mut self, key: String, value: String, timestamp: i32) {
        self.data
            .entry(key)
            .or_insert(vec![(0, String::new())])
            .push((timestamp, value));
    }

    fn get(&self, key: String, timestamp: i32) -> String {
        if let Some(timestamps) = self.data.get(&key) {
            let mut range = &timestamps[..];
            while range.len() > 1 {
                let (left, right) = range.split_at(range.len() / 2);
                range = match right.first() {
                    Some((x, _)) if timestamp < *x => left,
                    Some(_) => right,
                    None => unreachable!(),
                };
            }
            if let Some((_, value)) = range.first() {
                return value.clone();
            }
        }
        String::new()
    }
}

/**
 * Your TimeMap object will be instantiated and called as such:
 * let obj = TimeMap::new();
 * obj.set(key, value, timestamp);
 * let ret_2: String = obj.get(key, timestamp);
 */
#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        crate::assert_design! {
            obj: TimeMap;
            [new, set, get, get, set, get, get];
            [[], ["foo".into(), "bar".into(), 1], ["foo".into(), 1], ["foo".into(), 3], ["foo".into(), "bar2".into(), 4], ["foo".into(), 4], ["foo".into(), 5]];
            [null, null, "bar", "bar", null, "bar2", "bar2"];
        }
    }
}
