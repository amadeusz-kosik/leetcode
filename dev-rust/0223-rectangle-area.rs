impl Solution {

    fn overlap_line(a1: i32, a2: i32, b1: i32, b2: i32) -> i32 {
        let o1 = a1.max(b1);
        let o2 = a2.min(b2);
        return (o2 - o1).max(0);
    }

    pub fn compute_area(ax1: i32, ay1: i32, ax2: i32, ay2: i32, bx1: i32, by1: i32, bx2: i32, by2: i32) -> i32 {
        let overlap_x = Self::overlap_line(ax1, ax2, bx1, bx2);
        let overlap_y = Self::overlap_line(ay1, ay2, by1, by2);

        //     (        area_a         ) + (        area_b         ) - (    area_overlap     );
        return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - (overlap_x * overlap_y);
    }
}