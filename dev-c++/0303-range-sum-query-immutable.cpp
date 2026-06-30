class NumArray {
public:
    NumArray(vector<int>& nums) {
        sums = vector<int>(nums.size());
        sums[0] = nums[0];

        for(size_t i = 1; i < nums.size(); ++ i) {
            sums[i] = sums[i - 1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left == 0) { 
            return sums[right]; 
        } else {
            return sums[right] - sums[left - 1];
        }        
    }
private:
    vector<int> sums;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */