/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(const int* array, const int array_length, const int target, int* return_size) {
    for(size_t i = 0; i < array_length; ++ i) {
        for(size_t j = i + 1; j < array_length; ++ j) {
            if(array[i] + array[j] == target) {
                int *result  = (int *) calloc(2, sizeof(int));
                *return_size = 2;

                result[0] = i;
                result[1] = j;

                return result;
            }
        }
    }

    return NULL;
}