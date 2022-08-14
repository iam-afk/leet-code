use crate::Solution;

use std::collections::hash_map::Entry;
use std::collections::HashMap;
use std::collections::VecDeque;

impl Solution {
    pub fn find_ladders(
        begin_word: String,
        end_word: String,
        word_list: Vec<String>,
    ) -> Vec<Vec<String>> {
        let mut adjacents: HashMap<&String, Vec<&String>> = HashMap::new();
        Self::find_adjacents(
            &begin_word,
            &word_list,
            adjacents.entry(&begin_word).or_insert(Vec::new()),
        );
        for w in &word_list {
            if let Entry::Vacant(e) = adjacents.entry(&w) {
                Self::find_adjacents(w, &word_list, e.insert(Vec::new()));
            }
        }

        let mut queue = VecDeque::new();
        queue.push_back(&begin_word);
        let mut transform_from = HashMap::new();
        transform_from.insert(&begin_word, (0, Vec::new()));
        while let Some(last) = queue.pop_front() {
            if last == &end_word {
                continue;
            }
            let &(k, _) = transform_from.get(last).expect("last word");
            for word in adjacents.get(last).unwrap_or(&Vec::new()) {
                let e = transform_from.entry(word).or_insert((k + 1, Vec::new()));
                if e.0 == k + 1 {
                    e.1.push(last);
                    if e.1.len() == 1 {
                        queue.push_back(word);
                    }
                }
            }
        }
        let mut results = Vec::new();
        Self::restore(
            &mut results,
            &mut vec![end_word],
            &begin_word,
            &transform_from,
        );
        results
    }

    fn find_adjacents<'a>(word: &String, word_list: &'a [String], result: &mut Vec<&'a String>) {
        for w in word_list {
            if word.chars().zip(w.chars()).filter(|(a, b)| a != b).count() == 1 {
                result.push(w);
            }
        }
    }

    fn restore(
        results: &mut Vec<Vec<String>>,
        sequence: &mut Vec<String>,
        begin_word: &String,
        transform_from: &HashMap<&String, (i32, Vec<&String>)>,
    ) {
        let last = sequence.last().unwrap();
        if last == begin_word {
            let mut clone = sequence.clone();
            clone.reverse();
            results.push(clone);
        } else if let Some((_, from)) = transform_from.get(last) {
            for &word in from {
                sequence.push(word.to_string());
                Self::restore(results, sequence, begin_word, transform_from);
                sequence.pop();
            }
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test1() {
        let result = Solution::find_ladders(
            "hit".into(),
            "cog".into(),
            ["hot", "dot", "dog", "lot", "log", "cog"]
                .iter()
                .map(|&s| s.into())
                .collect(),
        );
        assert_eq!(
            result,
            vec![
                ["hit", "hot", "dot", "dog", "cog"],
                ["hit", "hot", "lot", "log", "cog"]
            ]
        );
    }

    #[test]
    fn test_big() {
        let begin_word: String = "cet".into();
        let end_word: String = "ism".into();
        let word_list: Vec<String> = [
            "kid", "tag", "pup", "ail", "tun", "woo", "erg", "luz", "brr", "gay", "sip", "kay",
            "per", "val", "mes", "ohs", "now", "boa", "cet", "pal", "bar", "die", "war", "hay",
            "eco", "pub", "lob", "rue", "fry", "lit", "rex", "jan", "cot", "bid", "ali", "pay",
            "col", "gum", "ger", "row", "won", "dan", "rum", "fad", "tut", "sag", "yip", "sui",
            "ark", "has", "zip", "fez", "own", "ump", "dis", "ads", "max", "jaw", "out", "btu",
            "ana", "gap", "cry", "led", "abe", "box", "ore", "pig", "fie", "toy", "fat", "cal",
            "lie", "noh", "sew", "ono", "tam", "flu", "mgm", "ply", "awe", "pry", "tit", "tie",
            "yet", "too", "tax", "jim", "san", "pan", "map", "ski", "ova", "wed", "non", "wac",
            "nut", "why", "bye", "lye", "oct", "old", "fin", "feb", "chi", "sap", "owl", "log",
            "tod", "dot", "bow", "fob", "for", "joe", "ivy", "fan", "age", "fax", "hip", "jib",
            "mel", "hus", "sob", "ifs", "tab", "ara", "dab", "jag", "jar", "arm", "lot", "tom",
            "sax", "tex", "yum", "pei", "wen", "wry", "ire", "irk", "far", "mew", "wit", "doe",
            "gas", "rte", "ian", "pot", "ask", "wag", "hag", "amy", "nag", "ron", "soy", "gin",
            "don", "tug", "fay", "vic", "boo", "nam", "ave", "buy", "sop", "but", "orb", "fen",
            "paw", "his", "sub", "bob", "yea", "oft", "inn", "rod", "yam", "pew", "web", "hod",
            "hun", "gyp", "wei", "wis", "rob", "gad", "pie", "mon", "dog", "bib", "rub", "ere",
            "dig", "era", "cat", "fox", "bee", "mod", "day", "apr", "vie", "nev", "jam", "pam",
            "new", "aye", "ani", "and", "ibm", "yap", "can", "pyx", "tar", "kin", "fog", "hum",
            "pip", "cup", "dye", "lyx", "jog", "nun", "par", "wan", "fey", "bus", "oak", "bad",
            "ats", "set", "qom", "vat", "eat", "pus", "rev", "axe", "ion", "six", "ila", "lao",
            "mom", "mas", "pro", "few", "opt", "poe", "art", "ash", "oar", "cap", "lop", "may",
            "shy", "rid", "bat", "sum", "rim", "fee", "bmw", "sky", "maj", "hue", "thy", "ava",
            "rap", "den", "fla", "auk", "cox", "ibo", "hey", "saw", "vim", "sec", "ltd", "you",
            "its", "tat", "dew", "eva", "tog", "ram", "let", "see", "zit", "maw", "nix", "ate",
            "gig", "rep", "owe", "ind", "hog", "eve", "sam", "zoo", "any", "dow", "cod", "bed",
            "vet", "ham", "sis", "hex", "via", "fir", "nod", "mao", "aug", "mum", "hoe", "bah",
            "hal", "keg", "hew", "zed", "tow", "gog", "ass", "dem", "who", "bet", "gos", "son",
            "ear", "spy", "kit", "boy", "due", "sen", "oaf", "mix", "hep", "fur", "ada", "bin",
            "nil", "mia", "ewe", "hit", "fix", "sad", "rib", "eye", "hop", "haw", "wax", "mid",
            "tad", "ken", "wad", "rye", "pap", "bog", "gut", "ito", "woe", "our", "ado", "sin",
            "mad", "ray", "hon", "roy", "dip", "hen", "iva", "lug", "asp", "hui", "yak", "bay",
            "poi", "yep", "bun", "try", "lad", "elm", "nat", "wyo", "gym", "dug", "toe", "dee",
            "wig", "sly", "rip", "geo", "cog", "pas", "zen", "odd", "nan", "lay", "pod", "fit",
            "hem", "joy", "bum", "rio", "yon", "dec", "leg", "put", "sue", "dim", "pet", "yaw",
            "nub", "bit", "bur", "sid", "sun", "oil", "red", "doc", "moe", "caw", "eel", "dix",
            "cub", "end", "gem", "off", "yew", "hug", "pop", "tub", "sgt", "lid", "pun", "ton",
            "sol", "din", "yup", "jab", "pea", "bug", "gag", "mil", "jig", "hub", "low", "did",
            "tin", "get", "gte", "sox", "lei", "mig", "fig", "lon", "use", "ban", "flo", "nov",
            "jut", "bag", "mir", "sty", "lap", "two", "ins", "con", "ant", "net", "tux", "ode",
            "stu", "mug", "cad", "nap", "gun", "fop", "tot", "sow", "sal", "sic", "ted", "wot",
            "del", "imp", "cob", "way", "ann", "tan", "mci", "job", "wet", "ism", "err", "him",
            "all", "pad", "hah", "hie", "aim",
        ]
        .iter()
        .map(|&s| s.into())
        .collect();
        let result = Solution::find_ladders(begin_word, end_word, word_list);
        assert_eq!(
            result,
            vec![
                ["cet", "cot", "con", "ion", "inn", "ins", "its", "ito", "ibo", "ibm", "ism"],
                ["cet", "cat", "can", "ian", "inn", "ins", "its", "ito", "ibo", "ibm", "ism"]
            ]
        );
    }
}
