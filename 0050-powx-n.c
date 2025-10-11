double myPow(double x, int n) {
    if(n == 0 || x == 1.0) {
        return 1.0;
    } else {
        long n_abs = n;
        double result = 1.0;
        
        if(n < 0)
            n_abs *= -1;

        while(n_abs != 0) {
            if(n_abs % 2 == 0) {
                x = x * x;
                n_abs = n_abs / 2;
            } else {
                result = result * x;
                n_abs = n_abs - 1;
            }
        }
        
        return (n < 0) ? 1.0 / result : result;
    }
}