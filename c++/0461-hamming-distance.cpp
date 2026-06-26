class Solution {
public:
    int hammingDistance(int x, int y) {
        int distance = 0;
        int mask = 1;

        for(int i = 1; i < 32; ++ i) {
            if((x & mask) != (y & mask)) {
                distance += 1;
            }

            mask <<= 1;
        }

        return distance;
    }
};
