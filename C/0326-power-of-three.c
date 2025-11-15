bool isPowerOfThree(int n) {
    if(n == 0)
        return false;

    if(n == 1)
        return true;

    long candidate = 3;

    while(candidate < INT_MAX) {
        if(n == candidate)
            return true;

        candidate = candidate * 3;
    }

    return false;    
}