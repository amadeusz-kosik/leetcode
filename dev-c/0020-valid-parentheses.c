bool is_left(const char c) {
    return (c == '(') || (c == '[') || (c == '{');
}

bool is_pair(const char l, const char r) {
    bool p1 = (l == '(' && r == ')');
    bool p2 = (l == '[' && r == ']');
    bool p3 = (l == '{' && r == '}');

    return p1 || p2 || p3;
}

bool isValid(char* s) {
    // S properties
    int s_len = strlen(s);

    if(s_len == 0)
        return true;

    if(s_len % 2 == 1)
        return false;

    if(s_len == 2)
        return is_pair(s[0], s[1]);

    // Stack
    char *stack_array = (char *) malloc(sizeof(char) * (s_len) / 2);
    int stack_index = -1;
    
    for(int i = 0; i < s_len; ++ i) {
        if(is_left(s[i])) { 
            // ( [ {
            if(stack_index == (s_len / 2) - 1)
                return false;

            ++ stack_index;
            stack_array[stack_index] = s[i];
        } else {
            // ) ] }
            if(stack_index == -1)
                return false;

            if(! is_pair(stack_array[stack_index], s[i])) 
                return false;
            
            -- stack_index;
        }
    }

    return stack_index == -1;
}