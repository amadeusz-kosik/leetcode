impl Solution {
    pub fn construct_rectangle(area: i32) -> Vec<i32> {
        let mut w: i32 = f64::sqrt(area as f64) as i32;
        
        while (area % w) != 0 {
            w -= 1;
        }

        return vec!(area / w, w);
    }
}