class Solution {
public:
    int reverse(int _x) {
        bool sign = (_x > 0);        
        unsigned int x = _x;         
        unsigned int result = 0;

        if(! sign) { x = -x; }

        while(x != 0) {
            if(result > INT_MAX / 10) { return 0; }

            result *= 10;
            result += (x % 10);
            x /= 10;
        }

        return (sign) ? (int) result : -((int) result);
    }
};