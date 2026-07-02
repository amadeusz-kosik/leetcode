class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool increasing = true;
        bool decreasing = true;

        int last_element = nums[0];

        for(int n: nums) {
            increasing &= (last_element >= n);
            decreasing &= (last_element <= n);

            if(! (increasing || decreasing)) {
                return false;
            }

            last_element = n;
        }

        return true;
    }
};