impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut result = vec!(vec!(1));

        for i in 1..(num_rows as usize) {
            let mut line = vec!(1);

            for j in 1..i {
                line.push(result[i - 1][j - 1] + result[i - 1][j]);
            }

            line.push(1);
            result.push(line);
        }

        return result;
    }
}