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
        char main = s[0] - 'A';
        vector<int> numCounts(26, 0);
        while (r < s.size()) {
            int cur = s[r] - 'A';
            numCounts[cur]++;
            if (numCounts[cur] > numCounts[main]) {
                main = cur;
            }

            // check validity
            if (k + numCounts[main] < r - l + 1) {
                while (k + numCounts[main] < r - l + 1) {
                    numCounts.at(s[l] - 'A')--;
                    l++;
                    for (int i = 0; i < numCounts.size(); i++) {
                        if (numCounts[i] > numCounts[main]) {
                            main = i;
                        }
                    }
                }
            } else {
                best = max(best, r - l + 1);
            }

            r++;
        }
        return best;
            
    }
};
