class Solution {
public:
    string intToRoman(const int num) const {
        std::stringstream result_builder;

        std::string lookup_1000[4] = { "", "M", "MM", "MMM" };
        result_builder << lookup_1000[num / 1000];

        std::string lookup_100[10] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
        result_builder << lookup_100[(num % 1000) / 100];

        std::string lookup_10[10] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
        result_builder << lookup_10[(num % 100) / 10];
  
        std::string lookup_1[10] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
        result_builder << lookup_1[(num % 10)];

        return result_builder.str();
    }
};