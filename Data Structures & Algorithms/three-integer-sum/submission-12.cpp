class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        // iterate through each number
        vector<vector<int>> solution = {};
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << "\n";
            if (i >= 1 && nums[i] == nums[i - 1]) continue;
            // two sum problem here
            // int target = -nums[i];
            int target = -nums.at(i);
            int low = i + 1;
            int high = nums.size() - 1;
            while (low < high) {
            // while (low < high && nums.at(low) + nums.at(high) != target) {
                int sum = nums[low] + nums[high];
                if (sum > target) {
                    high--;
                } else if (sum < target) {
                    low++;
                } else {
                    solution.push_back({nums[i], nums[low], nums[high]});

                    int last = nums[low];
                    while (nums[low] == last && low < high) low++;
                    last = nums[high];
                    while (nums[high] == last && low < high) high--;
                }
            }
        }

        return solution;
    }
};
