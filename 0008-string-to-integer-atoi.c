int myAtoi(char* s) {
    int s_len = strlen(s);
    int result = 0;
    int sign = 1;

    bool had_sign = false;
    bool is_reading = false;

    for(int i = 0; i < s_len; ++ i) {
        if(s[i] == '+' || s[i] == '-') {
            if(! had_sign && ! is_reading) {
                had_sign = true;
                is_reading = true;

                if(s[i] == '-')
                    sign = -1;
            } else {
                break;
            }
        } else if(s[i] >= '0' && s[i] <= '9') {
            is_reading = true;
            long buffer = ((long) result) * 10 + (int) (s[i] - '0');

            if(sign ==  1 &&  buffer >= INT_MAX)
                return INT_MAX;
            if(sign == -1 && -buffer <= INT_MIN)
                return INT_MIN;

            result = (int) buffer;
        } else if (s[i] == ' ') {
            if(! is_reading)
                continue;
            else
                break;
        } else {
            break;
        }
    }    

    return result * sign;
}