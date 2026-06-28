impl Solution {
    
    // 1
    // 1 1
    // 1 2 1 
    // 1 3 3 1
    // 1 4 6 4 1

    pub fn get_row(row_index: i32) -> Vec<i32> {
        let row_index = row_index as usize;
        let mut row = vec![0_i32; row_index + 1];
        row[0] = 1;

        for row_index in 1..=row_index {
            for i in (0..row_index).rev() {
                row[i + 1] += row[i];
            }
        }

        return row;
    }
}