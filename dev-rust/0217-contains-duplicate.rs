use std::collections::HashSet;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let nums_len = nums.len();
        let set: HashSet<i32> = HashSet::from_iter(nums);
        return nums_len != set.len();
    }
}