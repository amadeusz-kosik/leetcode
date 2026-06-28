impl Solution {
    pub fn count_primes(_n: i32) -> i32 {
        let n = (_n as usize);
        let mut future_primes = vec![true; n];

        for i in 2..(n.isqrt() + 1) {
            if future_primes[i] {
                let mut j = i + i;

                while j < n {
                    future_primes[j] = false;
                    j += i;
                }
            }
        }

        let mut result: i32 = 0;

        for i in 2..n {
            if future_primes[i] {
                result += 1;
            }                        
        }

        return result;
    }
}