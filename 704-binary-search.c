int search(int* nums, int numsSize, int target) {
    int left   = 0;
    int right  = numsSize;
    
    while(right - left > 3) {
        int mid = (left + right) / 2;

        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] > target) {
            right = mid;
        } else {
            left = mid;
        }
    }

    for(int i = left; i < right; ++ i) {
        if(nums[i] == target) 
            return i;
    }
    
    return -1;
}