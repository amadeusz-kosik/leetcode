impl Solution {

    pub fn is_palindrome(s: String) -> bool {
        let s_clean: String    = s.chars().filter(|c| c.is_alphanumeric()).collect();
        let s_straight: String = s_clean.trim().to_lowercase();
        let s_reversed: String = s_straight.chars().rev().collect();    

        return s_straight == s_reversed;
    }
}