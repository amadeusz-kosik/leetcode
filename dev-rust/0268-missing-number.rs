impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let mut sum: i32 = 0;
        let length = nums.len();

        for i in 0..length {
            sum += nums[i];
        }

        let expected = (length as i32) * (length as i32 + 1) / 2;
        return expected - sum;
    }
}