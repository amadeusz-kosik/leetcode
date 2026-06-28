#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> visited;

        for (auto const& [index, num]: nums | std::views::enumerate) {
            if(visited.contains(target - num)) {
                return std::vector { visited[target - num], (int) index };
            }
            visited[num] = index;
        }
 
        return std::vector { -1, -1 };
    }
};