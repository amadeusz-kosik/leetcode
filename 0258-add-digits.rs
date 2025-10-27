impl Solution {
    pub fn add_digits(num: i32) -> i32 {
        if num < 10 {
            num
        } else if num % 9 == 0 {
            9
        } else {
            num % 9
        }    
    }
}