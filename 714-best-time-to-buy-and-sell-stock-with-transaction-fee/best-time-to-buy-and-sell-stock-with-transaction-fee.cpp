class Solution {
public:
    int maxProfitUtill(int ind, int buy, vector<int>&prices, int fees, vector<vector<int>>&dp, int n){
        if(ind==n) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        long long profit =-1e9;
        if(buy) profit = max(-prices[ind]+maxProfitUtill(ind+1, 0, prices, fees, dp, n),
                              0 + maxProfitUtill(ind+1, 1, prices, fees, dp, n));
        else profit = max(prices[ind]-fees + maxProfitUtill(ind+1, 1, prices, fees, dp, n),
                           0 + maxProfitUtill(ind+1, 0, prices, fees, dp, n));
        return dp[ind][buy] = (int)profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return maxProfitUtill(0, 1, prices, fee, dp, n);
    }
};