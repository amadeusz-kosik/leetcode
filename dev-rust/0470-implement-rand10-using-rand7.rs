/** 
 * The rand7() API is already defined for you.
 * @return a random integer in the range 1 to 7
 * fn rand7() -> i32;
 */

impl Solution {
    pub fn rand10() -> i32 {
        let mut result: i32 = 0;

        loop {
            result = (rand7() - 1) * 7 + rand7();

            if result <= 40 {
                break;
            }
        }

        return (result % 10) + 1;
    }
}