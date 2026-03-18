class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        size_t read = 0;
        size_t write = 0;

        while(read < nums.size()) {
            if(nums[read] != val) {
                if(write != read) {
                    nums[write] = nums[read];
                }
                write += 1;
            }

            read += 1;
        }

        return write;
    }
};
