class Solution {
public:
    int arrangeCoins(int n) {
        int step = 1;

        while(n >= step) {
            n -= step;
            step += 1;
        }

        return step - 1;
    }
};