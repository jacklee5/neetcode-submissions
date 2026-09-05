class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;

        int best = 0;
        while (l < r) {
            int area = (r - l) * min(heights[l], heights[r]);
            best = max(area, best);
            if (heights[l] < heights[r]) {
                l++;
            } else {
                r--;
            }
        }

        return best;
    }
};
