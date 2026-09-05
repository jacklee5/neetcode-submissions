class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // buy starts at 0
        // sell starts 1
        // if the next number is more than current sell, move sell
        // if it larger than buy, move buy to that number

        int best = 0;
        int buy = 0;
        int sell = 1;
        while (sell < prices.size()) {
            int profit = prices[sell] - prices[buy];
            best = max(best, profit);
            cout << prices[buy] << " " << prices[sell] << "\n";

            if (prices[sell] < prices[buy]) {
                buy = sell;
            }
            sell++;
        }

        return best;
    }
};
