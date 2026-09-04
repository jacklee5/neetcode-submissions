class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // unordered_map<int, int> last_seen = {};
        // for (int i = 0; i < numbers.size(); i++) {
        //     last_seen[numbers[i]] = i;
        // }

        // for (int i = 0; i < numbers.size(); i++) {
        //     int cand = target - numbers[i];
        //     auto it = last_seen.find(cand);
        //     if (it != last_seen.end()) {
        //         int val = it->second;
        //         if (val > i) {
        //             return {i + 1, val + 1};
        //         }
        //     }
        // }

        for (auto start = numbers.begin(); start != numbers.end(); start++) {
            int cand = target - *start;
            auto it = lower_bound(start + 1, numbers.end(), cand);
            if (it != numbers.end() && *it == cand) {
                return {(int) (start - numbers.begin() + 1), (int) (it - numbers.begin() + 1)};
            }
        }
    }
};
