impl Solution {
    pub fn is_power_of_four(n: i32) -> bool {
        if n == 0 {
            return false;
        } 

        if n == 1 {
            return true;
        }

        let mut mask: i64 = 4;
        let n_64: i64 = n.into();

        while mask < (i32::MAX as i64) {
            if n_64 == mask {
                return true;
            }

            mask <<= 2;
        }

        return false;

    }
}