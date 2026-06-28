use std::collections::HashSet;


impl Solution {
    pub fn num_jewels_in_stones(jewels: String, stones: String) -> i32 {
        let mut jewels_set: HashSet<char> = HashSet::new();

        for jewel in jewels.chars() {
            jewels_set.insert(jewel);
        }

        let mut counter = 0;

        for stone in stones.chars() {
            if jewels_set.contains(&stone) {
                counter += 1;
            }
        }

        return counter;
    }
}