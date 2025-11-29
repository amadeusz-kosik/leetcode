impl Solution {

    pub fn my_sqrt(x: i32) -> i32 {
        if x == 0 { return 0; } 
        if x == 1 { return 1; }

        let mut  left: i32 = 0;
        let mut right: i32 = x;

        while left <= right {
            let mid = (left + right) / 2;

            if x / mid == mid {
                return mid;
            } else if (x / mid) < mid {
                right = mid - 1;
            } else {
                left  = mid + 1;
            }
        }

        return (left + right) / 2;
    }
}