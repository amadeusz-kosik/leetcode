impl Solution {
    pub fn find_max_consecutive_ones(nums: Vec<i32>) -> i32 {
        let mut count_current: i32 = 0;
        let mut count_max: i32 = 0;

        for i in nums {
            if i == 0 {
                count_current = 0;
            } else {
                count_current += 1;
                count_max = std::cmp::max(count_current, count_max);
            }
        }

        return count_max;
    }
}