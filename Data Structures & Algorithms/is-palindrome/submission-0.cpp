class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(
            remove_if(s.begin(), s.end(), [](unsigned char c) { 
                return !isalnum(c);
            }),
            s.end()
        );
        for (int i = 0; i < s.size() / 2; i++) {
            if (tolower(s[i]) != tolower(s[s.size() - 1 - i])) {
                cout << tolower(s[i]) << " " << tolower(s[s.size() - 1 - i]);
                return false;
            }
        }
        return true;
    }
};
