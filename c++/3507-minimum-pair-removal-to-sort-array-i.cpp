class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int operations_count = 0;

        while(true) {
            bool is_sorted = true;

            for(int i = 1; i < nums.size(); ++ i) {
                if(nums[i - 1] > nums[i]) {
                    is_sorted = false;
                    break;
                }
            }

            if(is_sorted) { return operations_count; }

            int min_pair = 1;

            for(int i = 1; i < nums.size(); ++ i) {
                if((nums[i] + nums[i - 1]) < (nums[min_pair - 1] + nums[min_pair])) {
                    min_pair = i;
                }
            }

            nums[min_pair - 1] += nums[min_pair];
            remove(nums, min_pair);

            operations_count += 1;
        }
        
        return -1;
    }

private:

    void remove(std::vector<int>& vec, std::size_t pos)
    {
        std::vector<int>::iterator it = vec.begin();
        std::advance(it, pos);
        vec.erase(it);
    }    
};
