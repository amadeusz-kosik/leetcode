int removeDuplicates(int* nums, int numsSize) {
    int i_read  = 1;
    int i_write = 1;

    while(i_read < numsSize) {
        if(nums[i_read] != nums[i_write - 1]) {
            nums[i_write] = nums[i_read];
            ++ i_read;
            ++ i_write;
        } else {
            ++ i_read;
        }
    }

    return i_write;
}