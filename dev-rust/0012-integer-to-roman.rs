impl Solution {

    fn encode_digit(c1: char, c5: char, c10: char, n: i32) -> String {
        return match n {
            0 => "".to_string(),
            1 => String::from_iter([c1]),
            2 => String::from_iter([c1, c1]),
            3 => String::from_iter([c1, c1, c1]),
            4 => String::from_iter([c1, c5]),
            5 => String::from_iter([c5]),
            6 => String::from_iter([c5, c1]),
            7 => String::from_iter([c5, c1, c1]),
            8 => String::from_iter([c5, c1, c1, c1]),
            9 => String::from_iter([c1, c10]),
            _ => "".to_string()
        }
    }

    pub fn int_to_roman(num: i32) -> String {
        let mut result: String = String::new();

        result += &Self::encode_digit('M', ' ', ' ', (num / 1000)       );
        result += &Self::encode_digit('C', 'D', 'M', (num % 1000) / 100 );
        result += &Self::encode_digit('X', 'L', 'C', (num % 100)  / 10  );
        result += &Self::encode_digit('I', 'V', 'X', (num % 10)         );   
      
        return result;
    }
}

