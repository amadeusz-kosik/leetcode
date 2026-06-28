use std::cmp;


impl Solution {

    fn pad(s: String, length: usize) -> String {
        let zeros = "0".repeat(length - s.len());
        return format!("{}{}", zeros, s);
    }

    fn reverse(s: String) -> String {
        s.chars().rev().collect()
    }

    pub fn add_binary(a: String, b: String) -> String {
        let max_length = cmp::max(a.len(), b.len());
        
        let a_rev = Self::reverse(Self::pad(a, max_length));
        let b_rev = Self::reverse(Self::pad(b, max_length));
        let mut in_iterator = a_rev.chars().zip(b_rev.chars());

        let mut result = String::with_capacity(max_length);
        let mut carry = false;

        for (ca, cb) in in_iterator { 
            match (ca, cb, carry) {

                ('0', '0', false) => {
                    result.push('0');
                    carry = false;
                }

                ('0', '1', false) => {
                    result.push('1');
                    carry = false;
                }

                ('0', '0', true) => {
                    result.push('1');
                    carry = false;
                }

                ('0', '1', true) => {
                    result.push('0');
                    carry = true;
                }

                ('1', '0', false) => {
                    result.push('1');
                    carry = false;
                }

                ('1', '1', false) => {
                    result.push('0');
                    carry = true;
                }

                ('1', '0', true) => {
                    result.push('0');
                    carry = true;
                }

                ('1', '1', true) => {
                    result.push('1');
                    carry = true;
                }

                (_, _, _) => {}
            }  
        }

        if carry {
            result.push('1');
        }

        return Self::reverse(result);
    }
}