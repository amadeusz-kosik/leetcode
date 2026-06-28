impl Solution {
    pub fn reverse(x: i32) -> i32 {
        if x == i32::MIN { return 0; }
        if x == 0        { return 0; }

        let is_negative = (x < 0);
        let mut remainder: i32 = x.abs();
        let mut result: i32 = 0;

        while(remainder != 0) {
            result = match result.checked_mul(10) { 
                Some(n) => n, 
                None    => return 0 
            };

            result = match result.checked_add(remainder % 10) { 
                Some(n) => n, 
                None    => return 0 
            };

            remainder /= 10;
        }

        if is_negative { return -result; }
        else           { return  result; }
    }
}
