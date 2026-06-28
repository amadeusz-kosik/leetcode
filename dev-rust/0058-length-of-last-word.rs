impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut words: Vec<&str> = s.split_whitespace().collect();
        words.retain(|&word| word.len() != 0);
        let size: usize = words.last().unwrap().len();
        return size.try_into().unwrap();
    }
}