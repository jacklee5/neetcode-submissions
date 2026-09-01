class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // count numbers
        std::unordered_map<int, int> num_map = {};
        for (int i = 0; i < nums.size(); i++){
            int candidate = target - nums[i];
            auto loc = num_map.find(candidate);
            if (loc != num_map.end())
            if (loc != num_map.end() && loc->second != i) {
                return {loc->second, i};
            }

            num_map[nums[i]] = i;
        }

        return {};
    }
};
