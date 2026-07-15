int myAtoi(char* s) {
    bool negative = false;
    size_t i = 0;
    long result = 0;

    while(s[i] == ' ') {
        i += 1;
    }

    if(s[i] == '+' || s[i] == '-') { 
        negative = (s[i] == '-');
        i += 1; 
    }

    while(s[i] >= '0' && s[i] <= '9') {
        result *= 10;

        if (negative) { result -= (s[i] - '0'); }
        else          { result += (s[i] - '0'); }   

        if(result > INT_MAX) { return INT_MAX; }
        if(result < INT_MIN) { return INT_MIN; }

        i += 1;   
    }

    return (int) result;
}