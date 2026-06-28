impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut i_read  = 0;
        let mut i_write = 0;

        while i_read < nums.len() {

            if nums[i_read] != val {
                if i_read != i_write {
                    nums[i_write] = nums[i_read];
                } 

                i_write += 1;
            }

            i_read += 1;
        }

        return i_write as i32;
    }
}