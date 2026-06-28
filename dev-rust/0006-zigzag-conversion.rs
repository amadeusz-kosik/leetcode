impl Solution {
    pub fn convert(s: String, num_rows: i32) -> String {
        if num_rows == 1 { return s; }
        
        let input: Vec<u8> = s.into_bytes();
        let num_rows = num_rows as usize;

        let mut rows: Vec<String> = vec![String::new(); num_rows];
        let mut current_row: usize = 0;
        let mut direction_up = false;

        for i in 0..input.len() {
            rows[current_row].push(input[i] as char);

            if direction_up {
                if current_row == 0 {
                    direction_up = false;
                    current_row = 1;
                } else {
                    current_row -= 1;
                }
            } else {
                if current_row == num_rows - 1 {
                    direction_up = true;
                    current_row = num_rows - 2;
                } else {
                    current_row += 1;
                }
            }
        }

        return rows.concat();
    }
}