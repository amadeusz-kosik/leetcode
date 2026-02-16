impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        let mut i_read:  usize = 1;
        let mut i_write: usize = 1;

        while i_read < nums.len() {
            if nums[i_read] != nums[i_write - 1] {
                nums[i_write] = nums[i_read];
                i_write += 1;
            }

            i_read += 1;
        }

        return i_write as i32;
    }
}