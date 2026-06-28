impl Solution {
    fn digit_to_letters(digit: char) -> Vec<char> {
        match digit {
           '2' => vec!('a', 'b', 'c'),
           '3' => vec!('d', 'e', 'f'),
           '4' => vec!('g', 'h', 'i'),
           '5' => vec!('j', 'k', 'l'),
           '6' => vec!('m', 'n', 'o'),
           '7' => vec!('p', 'q', 'r', 's'),
           '8' => vec!('t', 'u', 'v'),
           '9' => vec!('w', 'x', 'y', 'z'),
            _  => Vec::new()
        }
    }

    fn append(acc: String, digit: char) -> Vec<String> {
        Self::digit_to_letters(digit)
            .iter()
            .map(|d| format!("{}{}", acc, d))
            .collect()
    }

    pub fn letter_combinations(digits: String) -> Vec<String> {
        let mut results = vec!(String::from(""));

        for c in digits.chars() {
            results = results
                .into_iter()
                .flat_map(|s| Self::append(s, c))
                .collect()
        }
        
        return results;
    }
}
