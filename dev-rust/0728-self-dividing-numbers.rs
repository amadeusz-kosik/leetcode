impl Solution {

    fn is_self_dividing(number: i32) -> bool {
        for digit_as_c in number.to_string().chars() {
            let digit: i32 = (digit_as_c.to_digit(10).unwrap() as i32);

            if digit == 0 || number % digit != 0 {
                return false;
            }
        }

        return true;
    }
    
    pub fn self_dividing_numbers(left: i32, right: i32) -> Vec<i32> {
        let mut result = Vec::new();
        
        for i in left..(right + 1) {
            if Self::is_self_dividing(i) {
                result.push(i);
            }
        }
        
        return result;
    }
}