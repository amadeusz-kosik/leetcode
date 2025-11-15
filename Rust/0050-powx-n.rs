impl Solution {
    pub fn my_pow(mut x: f64, n: i32) -> f64 {
        if n == 0 || x == 1.0  {
            return 1.0;
        } else {
            let mut n_abs: i64 = n.into();
            let mut result: f64 = 1.0;
        
            if(n < 0) {
                n_abs = -n_abs;
            }

            while(n_abs != 0) {
                if(n_abs % 2 == 0) {
                    x = x * x;
                    n_abs = n_abs / 2;
                } else {
                    result = result * x;
                    n_abs = n_abs - 1;
                }
            }
        
            return if (n < 0) { 1.0 / result } else { result };
        }
    }
}
