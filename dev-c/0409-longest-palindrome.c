int longestPalindrome(char* s) {
    int s_len = strlen(s);

    int letters[64];

    for(int i = 0; i < s_len; ++ i) {
        ++ letters[(int) s[i] - 64];
    }

    int count_letters = 0;
    for(int i = 0; i < 64; ++ i) {
        if(letters[i] % 2 == 0) 
            count_letters += letters[i];
        else 
            count_letters += letters[i] - 1;
    }

    return (count_letters + 1 > s_len) ? s_len : count_letters + 1;
}