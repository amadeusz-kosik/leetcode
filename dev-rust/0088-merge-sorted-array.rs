impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        let mut i1 = m - 1;         // Reading index on nums1
        let mut i2 = n - 1;         // Reading index on nums2
        let mut iw = m + n - 1;     // Writing index

        while i1 >= 0 && i2 >= 0 {
            let ui1 = i1 as usize;
            let ui2 = i2 as usize;
            let uiw = iw as usize;

            if nums1[ui1] > nums2[ui2] {
                if iw != i1 { nums1[uiw] = nums1[ui1]; }                
                i1 -= 1;
            } else {
                nums1[uiw] = nums2[ui2];
                i2 -= 1;
            }

            iw -= 1;
        }

        while i1 >= 0 {
            let ui1 = i1 as usize;
            let uiw = iw as usize;

            if iw != i1 { nums1[uiw] = nums1[ui1]; }                
            i1 -= 1;
            iw -= 1;
        }

        while i2 >= 0 {
            let ui2 = i2 as usize;
            let uiw = iw as usize;

            nums1[uiw] = nums2[ui2];
            i2 -= 1;
            iw -= 1;
        }
    }
}