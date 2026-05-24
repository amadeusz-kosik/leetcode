class Solution {
public:
    int arraySign(vector<int>& nums) {
        bool is_positive = true;

        for(auto n: nums) {
            if(n == 0) return 0;
            if(n <  0) { is_positive = !is_positive; }
        }

        return (is_positive) ? 1 : -1;
    }
};