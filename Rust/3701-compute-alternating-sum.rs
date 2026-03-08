impl Solution {
    pub fn alternating_sum(nums: Vec<i32>) -> i32 {
        let mut negative = false;
        let mut result: i32 = 0;

        for n in nums {
            if negative { result -= n; }
            else        { result += n; }

            negative = !negative; 
        }

        return result;
    }
}