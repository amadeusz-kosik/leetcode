class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result = vector<int>(0x01 << n);

        result[0] = 0;
        result[1] = 1;

        uint16_t mask = 1;

        for(int i = 1; i < n; ++ i) {
            mask <<= 1; 

            for(int j = 0; j < mask; ++ j) {
                result[mask + j] = mask | result[mask - 1 - j];
            }
        }

        return result;
    }
};
