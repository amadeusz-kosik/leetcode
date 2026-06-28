class Solution {
public:
    int trailingZeroes(int n) {
        int count_fives = 0;

        for(int mask = 5; mask <= n; mask *= 5) {
            count_fives += n / mask;
        }

        return count_fives;
    }
};
