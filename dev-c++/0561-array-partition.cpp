class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int N = nums.size() / 2;
        sort(nums.begin(), nums.end());
        
        int result = 0;

        for(size_t i = 0; i < 2 * N; i += 2) {
            result += nums[i];
        }

        return result;
    }
};