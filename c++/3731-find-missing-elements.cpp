class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n_min = nums[0];
        int n_max = nums[0];

        std::unordered_set<int> n_all;

        for(int n: nums) {
            n_min = min(n_min, n);
            n_max = max(n_max, n);

            n_all.insert(n);
        }

        vector<int> result;

        for(int i = n_min; i < n_max; ++ i) {
            if(! n_all.contains(i)) {
                result.push_back(i);
            }
        }

        return result;
    }
};
