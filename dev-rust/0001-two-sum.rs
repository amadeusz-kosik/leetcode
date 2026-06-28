use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut seen: HashMap<i32, i32> = HashMap::new();

        for (index, num) in nums.iter().enumerate() {
            if let Some(other_index) = seen.get(num) {
                return vec![*other_index, index as i32];
            } else {
                seen.insert(target - num, index as i32);
            }
        }

        return vec![-1, -1];
    }
}