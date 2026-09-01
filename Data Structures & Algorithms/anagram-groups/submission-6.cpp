class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> m; // maps the locations of each set of anagrams
        for (int i = 0; i < strs.size(); i++) {
            string copy = strs[i];
            sort(copy.begin(), copy.end());
            m[copy].push_back(i);
        }

        vector<vector<string>> answer;
        for (auto& [_, indices] : m) {
            vector<string> group;
            for (int i : indices) {
                group.push_back(strs[i]);
            }
            answer.push_back(group);
        }

        return answer;
    }
};
