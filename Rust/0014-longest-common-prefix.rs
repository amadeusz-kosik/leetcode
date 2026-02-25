impl Solution {

    fn _longest_common_prefix(str_1: &String, str_2: &String) -> String {
        for i in (0..std::cmp::min(str_1.len(), str_2.len())).rev() {
            if &str_1[0..(i + 1)] == &str_2[0..(i + 1)] {
                return str_1[0..(i + 1)].to_string();
            }
        }

        return String::from("");
    }

    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut prefix: String = String::from(&strs[0]);

        for i in 1..strs.len() {
            prefix = Self::_longest_common_prefix(&prefix, &strs[i]);
        }

        return prefix;
    }
}