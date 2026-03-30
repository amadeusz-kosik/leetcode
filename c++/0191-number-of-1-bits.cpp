class Solution {
public:
    size_t hammingWeight(uint32_t n) {
        size_t result = 0;

        while(n != 0) {
            result += (n & 0x00000001);
            n >>= 1;
        }

        return result;
    }
};
