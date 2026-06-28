impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 {
            return false;
        } else if x < 10 {
            return true;
        } else {
            let mut digits: [i32; 32] = [0; 32];

            let left_index: usize = {
                let mut acc = x;
                let mut index = 0;

                while acc != 0 {
                    digits[index] = acc % 10;

                    acc /= 10;
                    index += 1;
                }

                index
            };

            let mut i = left_index - 1;
            let mut j = 0;

            while j < i {
                if digits[i] != digits[j] {
                    return false;
                }

                i -= 1;
                j += 1;
            }

            return true;
        }
    }
}