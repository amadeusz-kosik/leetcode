impl Solution {
 
    fn linear_search(nums: &Vec<i32>, target: i32, left: usize, right: usize) -> i32 {
        for i in left..right {
            if(nums[i] == target) {
                return i.try_into().unwrap();
            }
        }
        
        return -1;
    }

    fn binary_search(nums: &Vec<i32>, target: i32, left: usize, right: usize) -> i32 {
        if(right - left > 3) {
            let mid: usize = (left + right) / 2;

            if(nums[mid] == target) {
                return mid.try_into().unwrap();
            } else if(nums[mid] > target) {
                return Self::binary_search(nums, target, left, mid);
            } else {
                return Self::binary_search(nums, target, mid, right);
            }
        } else {
            return Self::linear_search(nums, target, left, right);
        }
    }

    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        Self::binary_search(&nums, target, 0, nums.len())
    }
}