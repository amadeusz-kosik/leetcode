impl Solution {

    fn overlap_line(a1: i32, a2: i32, b1: i32, b2: i32) -> bool {
        let o1 = a1.max(b1);
        let o2 = a2.min(b2);
        return o2 > o1;
    }

    pub fn is_rectangle_overlap(rec1: Vec<i32>, rec2: Vec<i32>) -> bool {
        let overlap_x = Self::overlap_line(rec1[0], rec1[2], rec2[0], rec2[2]);
        let overlap_y = Self::overlap_line(rec1[1], rec1[3], rec2[1], rec2[3]);

        return overlap_x && overlap_y;
    }
}