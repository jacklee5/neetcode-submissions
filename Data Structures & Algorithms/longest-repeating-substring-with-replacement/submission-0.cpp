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
            cout << l << " " << r << endl;
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
                    // move l until valid
                    // moving l main change the most frequent char
                    // how to find the new most frequent char?
                    // is the new most frequent char guaranteed to be r?
                    // CACACB
                    // is there a way to find the count of the most common substring for each l, r window?
                    // after incrementing r, main is guaranteed to the most common character
                    // or r is the same frequency as the other most frequent character
                    // given [l, r-1] is valid:
                        // if r = main, still valid
                        // if r != main,
                            // need to increment l to remove 1 non-main character
                            // if you keep encountering main characters, at some point it stops being the main character
                            // there is at most k non-main characters
                            // AAAAAAAABC
                            // k = 3 AAAAAABBBC
                        // if freq(r) = freq(main):
                            // need to increment l until either r or main is encountered, at which point
                        // idk, I can't figure out a simpler way, the easiest way would be to just find the new most frequent one at each step
                }
                // AAABBABBB, k=1
                // AAAB  AAABB  AAABBAB
                // AABB   AABB    AABBABB B
                // BBA
                // BBAB B B
                // if cur is main, the string is still valid no matter what
            } else {
                best = max(best, r - l + 1);
            }

            r++;
        }
        return best;
            
    }
};
