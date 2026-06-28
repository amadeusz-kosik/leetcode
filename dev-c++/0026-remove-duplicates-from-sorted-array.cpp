class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) { return 0; }

        size_t read = 1;
        size_t write = 1;

        while(read < nums.size()) {
            if(nums[read - 1] != nums[read]) {
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
