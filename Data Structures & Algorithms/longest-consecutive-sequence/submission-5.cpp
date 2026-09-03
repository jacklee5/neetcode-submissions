class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());

        int maxLen = 0;
        for (int num : seen) {
            if (seen.find(num - 1) == seen.end()) {
                int cur = num;
                int len = 1;
                while (seen.find(cur + 1) != seen.end()) {
                    len++;
                    cur++;
                }

                if (len > maxLen) {
                    maxLen = len;
                }
            }
        }

        return maxLen;
    }
};
