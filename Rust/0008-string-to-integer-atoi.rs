impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let mut leading  = true;
        let mut negative = false;
        let mut result: i32 = 0;

        for ch in s.chars() { 
            if leading && ch == ' ' { continue; }

            if leading && (ch == '+' || ch == '-') {
                if ch == '-' { negative = true; }

                leading = false;
                continue;
            }

            if ch >= '0' && ch <= '9' {
                let digit: i32 = (ch as i32) - 0x30;
                
                leading = false;
                result  = result.saturating_mul(10);

                if negative { result = result.saturating_sub(digit); }
                else        { result = result.saturating_add(digit); }     

                continue;
            }

            break;
        }

        return result ;
    }
}
