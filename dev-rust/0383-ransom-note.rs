impl Solution {
    pub fn can_construct(ransom_note: String, magazine: String) -> bool {
        let mut mask = [0; 26];

        magazine   .bytes().for_each(|c| mask[c as usize - 97] += 1);
        ransom_note.bytes().for_each(|c| mask[c as usize - 97] -= 1);
        
        return mask.into_iter().all(|x| x >= 0);
    }
}