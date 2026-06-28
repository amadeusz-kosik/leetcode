class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        int current = 0;
        int lastSeen[96];

        for(int i = 0; i < 96; ++ i) {
            lastSeen[i] = -1;
        }

        for(int i = 0; i < s.length(); ++ i) {
            int ch = (int) s[i] - 32;

            if(lastSeen[ch] < (i - current)) {
                lastSeen[ch] = i;
                current += 1;

                longest = max(longest, current);
            } else {
                current = i - lastSeen[ch];
                lastSeen[ch] = i;
            }
        }
        
        return longest;
    }
};

