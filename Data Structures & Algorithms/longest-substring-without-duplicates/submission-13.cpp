class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0;
        int r = 0;
        int best = 0;
        unordered_map<char, int> charPos;

        while (r < s.size()){
            // cout << l << " " << r << "\n";
            if (charPos.contains(s[r]) && charPos[s[r]] >= l) {
                best = max(best, r - l);
                l = charPos[s[r]] + 1;
            }
            charPos[s[r]] = r;
            r++;
        }
        best = max(best, r - l);

        return best;
    }
};
