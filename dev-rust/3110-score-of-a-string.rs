impl Solution {
    pub fn score_of_string(s: String) -> i32 {
        let mut score: i32 = 0;
        let values: Vec<i8> = s
            .chars()
            .map(|c| c as i8)
            .collect();

        for i in 1..(values.len()) {
            score += (values[i] - values[i - 1]).abs() as i32;
        }

        return score;
    }
}