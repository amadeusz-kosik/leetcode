impl Solution {

    fn search_linear(nums: &Vec<i32>, from: usize, to: usize, target: i32) -> usize {
        for mut i in from..to {
            if nums[i] >= target {
                return i;
            }
        }

        return to;
    }

    fn search_binary(nums: &Vec<i32>, from: usize, to: usize, target: i32) -> usize {
        let width = to - from;

        if (to - from) <= 4 {
            return Self::search_linear(nums, from, to, target);
        } else {
            let middle = (from + to) / 2;
            if nums[middle] == target {
                return middle;
            } else if nums[middle] < target {
                return Self::search_binary(nums, middle, to, target);
            } else {
                return Self::search_binary(nums, from, middle, target);
            }
        }
    }

    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        Self::search_binary(&nums, 0, nums.len(), target).try_into().unwrap()
    }
}