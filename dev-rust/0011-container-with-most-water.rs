use std::cmp;


impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut right = height.len() - 1;
        let mut max_area = 0;

        while(left < right) {
            max_area = cmp::max((right - left) as i32 * cmp::min(height[left], height[right]), max_area);

            if height[left] > height[right] {
                right -= 1;
            } else {
                left += 1;
            }
        }

        return max_area;
    }
}