int lengthOfLongestSubstring(char* s) {
    unsigned short s_len = strlen(s);

    unsigned short longest_l = 0;
    unsigned short current_l = 0;
    
    short last_seen[96];

    for(unsigned short i = 0; i < 96; ++ i) 
        last_seen[i] = -1;

    for(unsigned short i = 0; i < s_len; ++ i) {
        unsigned short current_char = ((unsigned short) s[i] - 32);

        if(last_seen[current_char] < (i - current_l)) {
            
            last_seen[current_char] = i;
            ++ current_l;

            if(current_l > longest_l) {
                longest_l = current_l;
            }
        } else {
            current_l = i - last_seen[current_char];
            last_seen[current_char] = i;
        }
    }

    return longest_l;
}