impl Solution {

    pub fn divide(dividend: i32, divisor: i32) -> i32 {
        let negative      = (dividend < 0) != (divisor < 0);
        let mut _dividend = i64::from(dividend).abs();
        let mut _divisor  = i64::from(divisor).abs();

        let mut n = 1;
        let mut result = 0;

        while (_divisor << 1) <= _dividend {
            _divisor <<= 1;
            n <<= 1;
        }

        while n > 0 {
            if _dividend >= _divisor {
                result += n;
                _dividend -= _divisor;
            }

            _divisor >>= 1;
            n >>= 1;
        }

        return (if negative {
            -result
        } else {
            result.min(i64::from(std::i32::MAX))
        }) as i32;
    }
}