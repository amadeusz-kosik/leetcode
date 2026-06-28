class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return (a[0] < b[0]) || (a[0] == b[0] && a[1] < b[1]);
        });

        std::vector<vector<int>> result;

        for(int i = 0; i < intervals.size(); ++ i) {
            int start = intervals[i][0];
            int end   = intervals[i][1];

            for(int j = i + 1; j < intervals.size(); ++ j) {
                if(intervals[j][0] > end) { break; }
                
                i += 1;
                end = std::max(end, intervals[j][1]);
            }

            result.push_back(vector<int> { start, end });
        }

        return result;
    }
};
