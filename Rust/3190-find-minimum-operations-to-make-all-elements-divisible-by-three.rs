impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        let mut result: i32 = 0;

        for num in nums {
            if num % 3 != 0 {
                result += 1;
            }
        }

        return result;
    }
}