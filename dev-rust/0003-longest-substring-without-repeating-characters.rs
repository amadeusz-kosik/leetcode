impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let mut s_len = s.len();

        let mut longest_l: i16 = 0;
        let mut current_l: i16 = 0;

        let mut last_seen: [i16; 96] = [-1; 96];
            
        for (_i, _current_char) in s.chars().enumerate() {
            let i = (_i as i16);
            let current_char = (_current_char as i16) - 32;

            if last_seen[current_char as usize] < (i - current_l) {
                last_seen[current_char as usize] = i;
                current_l += 1;

                if current_l > longest_l {
                    longest_l = current_l;
                }
            } else {
                current_l = i - last_seen[current_char as usize];
                last_seen[current_char as usize] = i;
            }
            
        }

        return longest_l as i32;
    }
}
