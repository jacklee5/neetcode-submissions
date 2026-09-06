class Solution {
public:
    int characterReplacement(string s, int k) {
        if (s.size() == 0) return 0;
        // move r until invalid
        // when invalid, most l until valid ig
        // keep track of counts and most count, swap over most when new letter surpasses

        int l = 0;
        int r = 0;
        int best = 0;
        int maxf = 0;
        vector<int> numCounts(26, 0);
        while (r < s.size()) {
            int cur = s[r] - 'A';
            numCounts[cur]++;
            if (numCounts[cur] > maxf) {
                maxf = numCounts[cur];
            }

            while (k + maxf < r - l + 1) {
                numCounts[s[l] - 'A']--;
                l++;
            }
            best = max(best, r - l + 1);

            r++;
        }
        return best;
            
    }
};
