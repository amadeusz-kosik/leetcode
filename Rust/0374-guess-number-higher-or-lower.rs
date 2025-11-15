/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * unsafe fn guess(num: i32) -> i32 {}
 */

impl Solution {
    unsafe fn guess_number(n: i32, left: i32, right: i32) -> i32 {
        if (right - left) < 3 {
            for i in left..=right {
                unsafe {
                    if guess(i) == 0 {
                        return i;
                    }
                }
            }

            return -1;
        }

        let sum: i64 = i64::from(right) + i64::from(left);
        let choice: i32 = (sum / 2) as i32;

        unsafe {
            let response: i32 = guess(choice);

            if response == -1 {
                return Self::guess_number(n, left, choice);
            } else if response == 0 {
                return choice;
            } else {
                return Self::guess_number(n, choice, right);
            }
        }    
    }

    unsafe fn guessNumber(n: i32) -> i32 {
        Self::guess_number(n, 0, n)
    }
}
