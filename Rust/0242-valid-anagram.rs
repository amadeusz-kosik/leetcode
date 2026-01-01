impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len() != t.len() {
            return false;
        }

        let mut histogram: HashMap<char, u32> = HashMap::new();

        for c in s.chars() {
            *histogram.entry(c).or_insert(0) += 1;
        }

        for c in t.chars() {
            *histogram.entry(c).or_insert(0) -= 1;
        }        

        return histogram.values().all(|&v| v == 0);
    }
}