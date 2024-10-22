class Solution {
public:
    int maxProfitUtill(vector<int>&prices, int n, vector<vector<int>>&dp, int ind, int buy){
        if(ind>=n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        long long profit = 0;
        if(buy) profit = max(-prices[ind]+maxProfitUtill(prices, n, dp, ind+1, 0),
                              0 + maxProfitUtill(prices, n, dp, ind+1, 1));
        else profit = max(prices[ind]+maxProfitUtill(prices, n, dp, ind+2, 1),
                            0 + maxProfitUtill(prices, n, dp, ind+1, 0));
        return dp[ind][buy] = (int)profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return maxProfitUtill(prices, n, dp, 0, 1);
    }
};