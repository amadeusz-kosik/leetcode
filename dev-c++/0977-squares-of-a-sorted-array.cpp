class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int positive_index = nums.size();

        for(int i = 0; i < nums.size(); ++ i) {
            if(nums[i] >= 0) {
                positive_index = i;
                break;
            }
        }

        for(int &n : nums) {
            n *= n;
        }

        int left = positive_index - 1;
        int right = positive_index;
        int write = 0;

        vector<int> result = vector<int>(nums.size());
        while(left >= 0 || right < nums.size()) {
            if(left < 0) { 
                while(right < nums.size()) {
                    result[write] = nums[right];
                    right += 1;
                    write += 1;
                }

                return result;
            }

            if(right == nums.size()) {
                while(left >= 0) {
                    result[write] = nums[left];
                    left -= 1;
                    write += 1;
                }

                return result;
            }

            if(nums[right] < nums[left]) {
                result[write] = nums[right];
                right += 1;
                write += 1;
            } else {
                result[write] = nums[left];
                left -= 1;
                write += 1;
            }

        }

        return result;
    }
};