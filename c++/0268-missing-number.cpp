class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int expected_sum = (nums.size() * (nums.size() + 1)) / 2;
        int actual_sum   = accumulate(nums.begin(), nums.end(), 0);

        return expected_sum - actual_sum;
    }
};