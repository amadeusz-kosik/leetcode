impl Solution {
    pub fn is_ugly(n: i32) -> bool {
        match n {
            0 =>
                return false,
                
            1 | 2 | 3 | 5 => 
                return true,
            
            _ => {
                for i in [2, 3, 5] {
                    if n % i == 0 {
                        return Self::is_ugly(n / i);
                    }
                }

                return false;
            }
        }
    }
}