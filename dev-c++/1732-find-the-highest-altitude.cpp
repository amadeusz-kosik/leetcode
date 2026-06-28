class Solution {
public:
    int largestAltitude(vector<int>& gains) {
        int current_altitude = 0;
        int max_altitude = 0;

        for(int gain: gains) {
            current_altitude += gain;
            max_altitude = max(max_altitude, current_altitude);
        }

        return max_altitude;
    }
};
