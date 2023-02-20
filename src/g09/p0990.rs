use crate::Solution;

impl Solution {
    pub fn equations_possible(equations: Vec<String>) -> bool {
        let mut p = [0; 26];
        for (i, x) in p.iter_mut().enumerate() {
            *x = i as u8;
        }
        for eq in equations
            .iter()
            .map(String::as_bytes)
            .filter(|b| b[1] == b'=')
        {
            Self::dsu_unite(eq[0] - b'a', eq[3] - b'a', &mut p);
        }

        for eq in equations
            .iter()
            .map(String::as_bytes)
            .filter(|b| b[1] == b'!')
        {
            if Self::dsu_get(eq[0] - b'a', &mut p) == Self::dsu_get(eq[3] - b'a', &mut p) {
                return false;
            }
        }

        true
    }

    fn dsu_get(v: u8, p: &mut [u8]) -> u8 {
        if v == p[v as usize] {
            v
        } else {
            p[v as usize] = Self::dsu_get(p[v as usize], p);
            p[v as usize]
        }
    }

    fn dsu_unite(a: u8, b: u8, p: &mut [u8]) {
        let a = Self::dsu_get(a, p);
        let b = Self::dsu_get(b, p);
        if a != b {
            p[a as usize] = b;
        }
    }
}

#[cfg(test)]
mod tests {
    use crate::Solution;

    #[test]
    fn example() {
        assert!(!Solution::equations_possible(vec![
            "a==b".into(),
            "b!=a".into()
        ]));
        assert!(Solution::equations_possible(vec![
            "b==a".into(),
            "a==b".into()
        ]))
    }
}
