/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
double* convertTemperature(double celsius, int* returnSize) {
    double *result = (double *) malloc(sizeof(double) * 2);
    *returnSize = 2;
    result[0] = celsius       + 273.15;
    result[1] = celsius * 1.8 +  32.00;
    return result;
}