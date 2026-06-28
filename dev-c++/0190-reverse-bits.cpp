class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int result = 0x00000000;
        
        for(int i = 0; i < 32; ++ i) {
            result <<= 1;
            result |= (n & 0x00000001);
            n >>= 1;
        }

        return result;
    }
};
