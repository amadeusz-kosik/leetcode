use std::collections::HashSet;

impl Solution {
    pub fn find_the_difference(s: String, t: String) -> char {
        let mut mask = [0; 26];

        t.bytes().for_each(|c| mask[c as usize - 97] += 1);
        s.bytes().for_each(|c| mask[c as usize - 97] -= 1);
        
        for c in 0..26 {
            if mask[c] > 0 {
                return (c as u8 + 97) as char;
            }
        }

        return '?';
    }
}