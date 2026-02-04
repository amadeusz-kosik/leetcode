impl Solution {
    pub fn convert_to_base7(num: i32) -> String {
        let mut base:   u32 = 1;
        let mut result: i32 = 0;
        let mut state:  u32 = num.abs() as u32;

        while state != 0 {
            let digit: u8 = (state % 7) as u8;
            state /= 7;
            
            result += (digit as u32 * base) as i32;
            base   *= 10;
        }

        if (num < 0) {
            result *= -1;
        }

        return result.to_string();
    }
}