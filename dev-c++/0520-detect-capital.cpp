class Solution {
public:
    bool detectCapitalUse(string word) {
        bool all_capitals = std::isupper(static_cast<unsigned char>(word[0]));
        bool no_capitals = !all_capitals;
        bool first_capital = all_capitals;

        for(int i = 1; i < word.size(); ++ i) {
            bool is_upper = std::isupper(static_cast<unsigned char>(word[i]));

            all_capitals &= is_upper;
            no_capitals &= !is_upper;
            first_capital &= !is_upper;
        }

        return all_capitals || no_capitals || first_capital;
    }
};