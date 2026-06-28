impl Solution {
    pub fn height_checker(heights: Vec<i32>) -> i32 {
        let mut sorted_heights = heights.clone();
        sorted_heights.sort();
        
        let mut count: i32 = 0;

        for (x, y) in heights.iter().zip(sorted_heights.iter()) {
            if x != y {
                count += 1;
            }
        }

        return count;
    }
}