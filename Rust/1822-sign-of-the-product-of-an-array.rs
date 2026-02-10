impl Solution {

    pub fn array_sign(nums: Vec<i32>) -> i32 {
        let mut negative = false;

        for n in nums {
            if n == 0 { return 0; }
            if n <  0 { negative = !negative; }
        }

        return if negative { -1 } else { 1 };
    }
}