class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int N = nums.size();
        vector<int> result(2 * N);

        for(int i = 0; i < N; ++ i) {
            result[i]     = nums[i];
            result[N + i] = nums[i];
        }

        return result;
    }
};