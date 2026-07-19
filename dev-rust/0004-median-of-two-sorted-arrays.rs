impl Solution {

    fn merge_vectors(nums_1: Vec<i32>, nums_2: Vec<i32>) -> Vec<i32> {
        let mut result = Vec::with_capacity(nums_1.len() + nums_2.len());

        let mut read_1 = 0;
        let mut read_2 = 0;

        while read_1 < nums_1.len() && read_2 < nums_2.len() {
            if nums_1[read_1] <= nums_2[read_2] {
                result.push(nums_1[read_1]);
                read_1 += 1;
            } else {
                result.push(nums_2[read_2]);
                read_2 += 1;
            }
        }

        while read_1 < nums_1.len() {
            result.push(nums_1[read_1]);
            read_1 += 1;
        }

        while read_2 < nums_2.len() {
            result.push(nums_2[read_2]);
            read_2 += 1;
        }
        
        return result;
    }

    pub fn find_median_sorted_arrays(nums_1: Vec<i32>, nums_2: Vec<i32>) -> f64 {
        let nums_merged = Self::merge_vectors(nums_1, nums_2);

        if nums_merged.len() % 2 == 0 {
            return (nums_merged[(nums_merged.len() / 2) - 1] + nums_merged[(nums_merged.len() / 2)]) as f64 / 2.0; 
        } else {
            return nums_merged[(nums_merged.len() / 2)].into();
        }
    }
}