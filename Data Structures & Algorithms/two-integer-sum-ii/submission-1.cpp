class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> last_seen = {};
        for (int i = 0; i < numbers.size(); i++) {
            last_seen[numbers[i]] = i;
        }

        for (int i = 0; i < numbers.size(); i++) {
            int cand = target - numbers[i];
            if (last_seen.contains(cand) && last_seen[cand] > i) {
                return {i + 1, last_seen[cand] + 1};
            }
        }
    }
};
