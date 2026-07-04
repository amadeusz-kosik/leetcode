// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lastKnownGood = 0;
        int firstKnownBad = n;

        while(firstKnownBad - lastKnownGood > 1) {
            long guess = ((long) firstKnownBad + (long) lastKnownGood) / 2;
            bool result = isBadVersion(guess);

            if(result) {
                firstKnownBad = guess;
            } else {
                lastKnownGood = guess;
            }

        }

        return firstKnownBad;
    }
};