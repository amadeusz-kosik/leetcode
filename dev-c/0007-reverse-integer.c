int reverse(int x){  
    unsigned int abs_x = x;         
    unsigned int result = 0;

    if(x < 0) { abs_x = -abs_x; }

    while(abs_x != 0) {
        if(result > INT_MAX / 10) { return 0; }

        result *= 10;
        result += (abs_x % 10);
        abs_x /= 10;
    }

    return (x >= 0) ? (int) result : -((int) result);
}