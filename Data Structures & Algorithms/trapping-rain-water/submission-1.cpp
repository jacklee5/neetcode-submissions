class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix(height.size());
        vector<int> suffix(height.size());

        int largest = 0;
        for (int i = 0; i < height.size(); i++) {
            if (height[i] > largest) {
                largest = height[i];
            }
            prefix[i] = largest;
        }

        largest = 0;
        for (int i = height.size() - 1; i >= 0; i--) {
            if (height[i] > largest) {
                largest = height[i];
            }
            suffix[i] = largest;
        }

        int total = 0;
        for (int i = 0; i < height.size(); i++) {
            total += min(prefix[i], suffix[i]) - height[i];
        }

        return total;
    }

    
};
