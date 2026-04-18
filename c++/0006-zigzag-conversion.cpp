#include <string>

class Solution {
public:
    string convert(string s, int numRows) {        
        if(numRows == 1) { return s; }

        size_t current_row = 0;
        bool direction_up = false;

        vector<string> rows = vector<string>(numRows);
        for(int i = 0; i < numRows; ++ i) 
            rows[i] =  "";

        for(int i = 0; i < s.size(); ++ i) {
            rows[current_row] += s[i];

            if(direction_up) {
                if (current_row == 0) {
                    direction_up = false;
                    current_row = 1;
                } else {
                    current_row -= 1;
                }
            } else {
                if (current_row == numRows - 1) {
                    direction_up = true;
                    current_row = numRows - 2;
                } else {
                    current_row += 1;
                }
            }
        }

        string result = "";

        for(int i = 0; i < numRows; ++ i)
            result += rows[i];

        return result;
    }
};


