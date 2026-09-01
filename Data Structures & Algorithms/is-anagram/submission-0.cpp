class Solution {
public:
    bool isAnagram(string s, string t) {
        std::vector<int> charCounts(26, 0);

        for (char c : s) {
            charCounts.at(c - 'a')++;
        }
        for (char c : t) {
            charCounts.at(c - 'a')--;
        }
        for (int count : charCounts) {
            if (count != 0) return false;
        }

        return true;
    }
};
