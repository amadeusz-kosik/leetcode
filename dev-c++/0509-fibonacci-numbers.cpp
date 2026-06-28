class Solution {
public:
    int fib(int n) {
        if(n == 0) { return 0; }
        if(n == 1) { return 1; }

        int values[2] = { 0, 1 };

        for(int i = 0; i < n; ++ i) {
            values[i % 2] = values[0] + values[1];
        }

        return values[n % 2];
    }
};
