class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // count numbers
        // std::unordered_map<int, int> num_map = {};
        const int RANGE = 10000000;
        std::vector<int> num_map(RANGE * 2 + 1, -1);
        for (int i = 0; i < nums.size(); i++){
            int candidate = target - nums[i];
            if (candidate + RANGE > num_map.size()) continue;
            int loc = num_map.at(candidate + RANGE);
            if (loc != -1) {
                return {loc, i};
            }

            num_map[nums[i] + RANGE] = i;
        }

        return {};
    }
};
