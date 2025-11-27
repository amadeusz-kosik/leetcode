impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
        if n == 0 {
            return false;
        } 

        if n == 1 {
            return true;
        }

        let mut candidate: i64 = 3;
        let n_64: i64 = n.into();

        while candidate < (i32::MAX as i64) {
            if n_64 == candidate {
                return true;
            }

            candidate *= 3;
        }

        return false;
    }
}