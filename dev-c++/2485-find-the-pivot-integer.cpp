class Solution {
public:
    int pivotInteger(int n) {
        for(int i = n; i > 0; -- i) {
            // Left sum
            int sum_left_dbl  = i * (i + 1);
            int sum_right_dbl = n * (n + 1) - i * (i - 1);

            if(sum_left_dbl == sum_right_dbl) { return i; }
            if(sum_left_dbl < sum_right_dbl)  { return -1; }
        }

        return -1;
    }
};
