class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // [1,   2,  8, 48] take i - 1 from rtl
        // [48, 48, 24,  6] and  i + 1 from ltr
        vector<int> rtl(nums.size());
        vector<int> ltr(nums.size());
        vector<int> result;
        result.reserve(nums.size());

        // populate rtl
        int acc = 1;
        for (int i = 0; i < nums.size(); i++) {
            acc *= nums[i];
            rtl[i] = acc;
        }

        // populate ltr
        acc = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            acc *= nums[i];
            ltr[i] = acc;
        }

        for (int i = 0; i < nums.size(); i++) {
            int left = i > 0 ? rtl[i - 1] : 1;
            int right = i + 1 < nums.size() ? ltr[i + 1] : 1;
            result.push_back(left * right);
        }

        return result;
    }
};
