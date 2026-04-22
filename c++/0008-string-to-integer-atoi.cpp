#include <numeric>


class Solution {
public:
    int myAtoi(string s) {
        bool leading = true;
        bool negative = false;
        long result = 0;

        for(int i = 0; i < s.size(); ++ i) {
            if(leading && s[i] == ' ') {
                continue;
            }

            if(leading && s[i] == '+') {
                leading = false;
                continue;
            }

            if(leading && s[i] == '-') {
                leading = false;
                negative = true;
                continue;
            }

            if(s[i] >= '0' && s[i] <= '9') {
                leading = false;
                result *= 10;

                if (negative) { result -= (s[i] - '0'); }
                else          { result += (s[i] - '0'); }   

                if(result > INT_MAX) { return INT_MAX; }
                if(result < INT_MIN) { return INT_MIN; }

                continue;                
            }
            
            break;
        }

        return (int) result;
    }
};

