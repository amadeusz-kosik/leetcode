impl Solution {

    fn _digit(c: char) -> u8 {
        match c.to_digit(10) {
            Some(d) => { d as u8 },
            None    => { 0 as u8 }
        }
    }

    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut col_mask: [u16; 9] = [0; 9];
        let mut row_mask: [u16; 9] = [0; 9];
        let mut sub_mask: [u16; 9] = [0; 9];

        for row in 0..9 {
            for col in 0..9 {
                let digit = Self::_digit(board[row][col]);
                let sub = (row / 3) * 3 + (col / 3);

                if digit == 0 {
                    continue;
                }  
                
                if col_mask[col] & (1 << digit) != 0 { return false; }
                if row_mask[row] & (1 << digit) != 0 { return false; }
                if sub_mask[sub] & (1 << digit) != 0 { return false; }

                col_mask[col] |= (1 << digit);
                row_mask[row] |= (1 << digit);
                sub_mask[sub] |= (1 << digit);
            }
        }

        return true;
    }
}