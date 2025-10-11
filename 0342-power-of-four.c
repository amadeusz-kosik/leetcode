bool isPowerOfFour(int n) {
    if(n == 0)
        return false;

    if(n == 1)
        return true;

    long mask = 4;

    while(mask < INT_MAX) {
        if(n == mask)
            return true;

        mask = mask << 2;
    }

    return false;
}