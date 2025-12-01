impl Solution {
    pub fn fizz_buzz(n: i32) -> Vec<String> {
        return (1..=n)
            .map(|x| 
                if (x % 3 == 0) && (x % 5 == 0) {
                    "FizzBuzz".to_string()
                } else if (x % 3 == 0) {
                    "Fizz".to_string()
                } else if (x % 5 == 0) {
                    "Buzz".to_string()
                } else {
                    x.to_string()
                }            
            )
            .collect()
    }
}