class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) { return false; }
        if(n == 1) { return true;  }

        long mask = 2;

        for(int i = 0; i < 31; ++ i) {
            if(n == mask) { return true; }
            mask <<= 1;
        }

        return false;
    }
};

