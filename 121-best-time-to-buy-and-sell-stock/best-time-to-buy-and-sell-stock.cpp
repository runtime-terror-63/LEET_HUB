class Solution {
public:
    int maxProfit(vector<int>& prices) {
       /* int buy = min(prices.begin(), prices.end());
        int sell = max(prices[buy]+1, prices.end());
        if(buy<sell)  */

       int mini = prices[0], profit = 0, n = prices.size();
        for (int i = 1; i < n; i++)
        {
            int cost = prices[i] - mini;
        // cout << cost << endl;
            profit = max(profit, cost);
            mini = min(mini, prices[i]);
        }
        return profit;
    }
};