impl Solution {
    pub fn min_operations(nums: Vec<i32>, k: i32) -> i32 {
        let sum: i32 = nums.into_iter().sum();
        return sum % k;
    }
}