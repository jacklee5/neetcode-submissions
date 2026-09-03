class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen = {};
        for (int num : nums) {
            seen.insert(num);
        }

        vector<int> starts = {};
        for (int num : seen) {
            if (seen.find(num - 1) == seen.end()) {
                starts.push_back(num);
            }
        }

        int maxLen = 0;
        for (int start : starts) {
            int cur = start;
            int len = 1;
            while (seen.find(cur + 1) != seen.end()) {
                len++;
                cur++;
            }

            if (len > maxLen) {
                maxLen = len;
            }
        }

        return maxLen;
    }
};
