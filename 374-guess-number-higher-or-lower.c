int guess(int num);

int guessNumber(int n){
    int left  = 0;
    int right = n;

	while(true) {
        if ((right - left) < 3) {
            for(int i = left; i <= right; ++ i) {
                if(guess(i) == 0) {
                    return i;
                }
            }

            return -1;
        }

        long sum = ((long) right + (long) left);
        int choice = (int) (sum / 2);
        int response = guess(choice);

        if(response == -1) {
            right = choice;
        } else if(response == 0) {
            return choice;
        } else {
            left = choice;
        }
    }
}