impl Solution {
    pub fn rotate(nums: &mut Vec<i32>, k: i32) {
        // 0ms, 3.37 MB
        let split_index = ((nums.len() as i32) - (k % nums.len() as i32)) as usize;
        let (left, right) = nums.split_at(split_index);
        *nums = [right, left].concat();

        // 0ms, 3.77 MB
        // let k = k as usize % nums.len();
        // nums.reverse();
        // nums[..k].reverse();
        // nums[k..].reverse();
    }
}