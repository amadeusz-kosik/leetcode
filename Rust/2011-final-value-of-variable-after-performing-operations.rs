impl Solution {
    pub fn final_value_after_operations(operations: Vec<String>) -> i32 {
        let mut x: i32 = 0;

        for operation in operations {
            match operation.as_str() {
                "++X" => {x += 1}
                "--X" => {x -= 1}
                "X++" => {x += 1}
                "X--" => {x -= 1}
                _     => {}
            }
        }

        return x;
    }
}