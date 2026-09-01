class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // count numbers
        std::unordered_map<int, int> num_map = {};
        for (int i = 0; i < nums.size(); i++){
            num_map[nums[i]] = i;
        }

        for (auto& [key, value] : num_map) {
            std::cout << key << value << "\n";
        }

        // std::cout << num_map.find(0)->first << "\n";
        std::cout << "finding 0" << (num_map.find(0) == num_map.end() ? 157 : num_map.find(0)->second) << "\n";

        // find answer
        for (int i = 0; i < nums.size(); i++) {
            int candidate = target - nums[i];
            std::cout << i << "\n";
            std::cout << candidate << "\n";
            auto loc = num_map.find(candidate);
            if (loc != num_map.end())
                std::cout << loc->first << "\n";
            if (loc != num_map.end() && loc->second != i) {
                return {i, loc->second};
            }
        }

        return {};
    }
};
