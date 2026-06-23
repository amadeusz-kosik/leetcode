class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int col = ((char) coordinates[0]) - 'a';
        int row = ((char) coordinates[1]) - '1';

        return (row + col) % 2;
    }
};
