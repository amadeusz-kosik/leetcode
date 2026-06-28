impl Solution {
    pub fn move_zeroes(nums: &mut Vec<i32>) {
        let mut i_read:  usize = 0;
        let mut i_write: usize = 0;

        while i_read < nums.len() {
            if nums[i_read] != 0 {
                if i_read != i_write {
                    nums[i_write] = nums[i_read];
                }

                i_write += 1;
            } // else: skip

            i_read += 1;
        }

        while i_write < nums.len() {
            nums[i_write] = 0;
            i_write += 1;
        }
    }
}