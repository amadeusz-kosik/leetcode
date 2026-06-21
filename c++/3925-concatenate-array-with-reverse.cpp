class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {
        size_t N = nums.size();
        nums.resize(N * 2);

        for(int i = 0; i < N; ++ i) {
            nums[N + i] = nums[N - i - 1];
        }

        return nums;
    }
};
