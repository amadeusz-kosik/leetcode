impl Solution {
    pub fn remove_duplicates(nums: &mut Vec<i32>) -> i32 {
        if nums.len() < 3 { return nums.len() as i32; }

        let mut i_read  : usize  = 2;
        let mut i_write : usize  = 2;
        let mut last_value: i32  = 0;

        while i_read < nums.len() {
            if nums[i_write - 2] != nums[i_read] {
                nums[i_write] = nums[i_read];

                i_write += 1;
            }

            i_read += 1;
        }

        return i_write as i32;
    }
}