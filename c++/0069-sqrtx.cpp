class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) { return 0; }
        if(x == 1) { return 1; }

        int left  = 0;
        int right = x;

        while(left <= right) {
            int mid  = (left + right) / 2;
            int test = (x / mid) - mid;

            if(test == 0) { return mid; }
            else if(test < 0) { right = mid - 1; }
            else { left = mid + 1; }
        }

        return (left + right) / 2;
    }
};
