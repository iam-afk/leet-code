use crate::Solution;

impl Solution {
    pub fn calculate(s: String) -> i32 {
        #[derive(Debug)]
        enum Token {
            Op(u8),
            Number(i32),
            LParen,
            RParen,
        }
        struct Lexer<'a> {
            input: &'a [u8],
        }
        impl Lexer<'_> {
            fn next(&mut self) -> Option<Token> {
                loop {
                    match self.input {
                        [] => return None,
                        [b' ', rest @ ..] => self.input = rest,
                        [b'(', rest @ ..] => {
                            self.input = rest;
                            return Some(Token::LParen);
                        }
                        [b')', rest @ ..] => {
                            self.input = rest;
                            return Some(Token::RParen);
                        }
                        [op @ (b'+' | b'-'), rest @ ..] => {
                            self.input = rest;
                            return Some(Token::Op(*op));
                        }
                        [d @ b'0'..=b'9', rest @ ..] => {
                            self.input = rest;
                            let mut v = *d as i32 - b'0' as i32;
                            while let [d @ b'0'..=b'9', rest @ ..] = self.input {
                                v = v * 10 + *d as i32 - b'0' as i32;
                                self.input = rest;
                            }
                            return Some(Token::Number(v));
                        }
                        [_, ..] => unreachable!(),
                    }
                }
            }
        }
        let mut lexer = Lexer {
            input: s.as_bytes(),
        };

        fn id(lexer: &mut Lexer) -> i32 {
            match lexer.next() {
                Some(Token::Number(v)) => v,
                Some(Token::LParen) => expr(lexer),
                Some(Token::Op(b'-')) => -id(lexer),
                _ => unreachable!(),
            }
        }

        fn expr(lexer: &mut Lexer) -> i32 {
            let mut result = id(lexer);
            while let Some(Token::Op(op)) = lexer.next() {
                result = match op {
                    b'+' => result + id(lexer),
                    b'-' => result - id(lexer),
                    _ => unreachable!(),
                }
            }
            return result;
        }

        expr(&mut lexer)
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn example() {
        assert_eq!(Solution::calculate("1 + 1".into()), 2);
        assert_eq!(Solution::calculate(" 2-1 + 2 ".into()), 3);
        assert_eq!(Solution::calculate("(1+(4+5+2)-3)+(6+8)".into()), 23);
    }

    #[test]
    fn test() {
        assert_eq!(Solution::calculate("-2+ 1".into()), -1);
    }
}
