class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int result = 0;

        for(int n: nums) {
            if(n % 2 == 0) {
                result |= n;
            }
        }

        return result;
    }
};