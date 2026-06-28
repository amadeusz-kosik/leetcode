class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int positives_count = 0;

        for(auto n: nums) {
            if(n > 0) { positives_count += 1; }
        }

        // Use available space in input array:
        //  on each step put nums[i - 1] number on its correct space
        //  skip if swap would "swap" identical values to not get into infinite loop

        for(int i = 1; i <= nums.size(); ++ i) {
            if(nums[i - 1] <= 0 || nums[i - 1] > positives_count) { 
                nums[i - 1] = 0; 
            } else {
                if(nums[i - 1] != i) {
                    if(nums[nums[i - 1] - 1] == nums[i - 1]) { 
                        nums[i - 1] = 0; 
                    } else {
                        // swap: nums[i - 1], nums[nums[i - 1] - 1]
                        int temp = nums[i - 1];
                        nums[i - 1] = nums[nums[i - 1] - 1];
                        nums[temp - 1] = temp;

                        if(nums[i - 1] <= i - 1) { -- i; }
                    }
                }
            }
        }

        for(int i = 1; i <= positives_count; ++ i) {
            if(nums[i - 1] != i) { return i; }
        }
        
        return positives_count + 1;
    }
};
