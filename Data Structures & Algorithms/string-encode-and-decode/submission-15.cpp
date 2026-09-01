class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for (string str : strs) {
            cout << ((unsigned int) (unsigned char) str.size()) << "\n";
            result += ((unsigned char) str.size());
            result += str;
        }
        return result;
    }

    vector<string> decode(string s) {
        int i = 0;
        vector<string> result;
        while (i < s.size()) {
            int len = (unsigned char) s[i];
            cout << i << " " << len << " ";
            if (len == 0)
                result.push_back("");
            else
                result.push_back(s.substr(i + 1, len));
            i = i + len + 1;
        }
        return result;
    }
};
