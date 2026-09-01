class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts = {};
        vector<vector<int>> buckets(nums.size() + 1);
        for (int num : nums) {
            counts[num]++;
        }

        for (auto& [key, value] : counts) {
            buckets[value].push_back(key);
        }

        vector<int> result;
        result.reserve(k);
        int bucket = nums.size();
        while (buckets[bucket].size() < k) {
            if (buckets[bucket].size() > 0) {
                result.insert(result.end(), buckets[bucket].begin(), buckets[bucket].end());
                k -= buckets[bucket].size();
            }
            bucket--;
        }

        result.insert(result.end(), buckets[bucket].begin(), buckets[bucket].begin() + k);
        return result;
    }
};
