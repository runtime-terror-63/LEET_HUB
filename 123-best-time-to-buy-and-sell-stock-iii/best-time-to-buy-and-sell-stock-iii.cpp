class Solution {
public:
    int maxProfitUtill(int ind, int buy, int cnt, vector<int>&prices, int n, vector<vector<vector<int>>>&dp){
        if(ind==n || cnt==0) return 0;
        if(dp[ind][buy][cnt] != -1) return dp[ind][buy][cnt];
        long long profit = -1e9;
        if(buy) profit = max(-prices[ind] + maxProfitUtill(ind+1, 0, cnt, prices, n, dp), 
                                0 + maxProfitUtill(ind+1, 1, cnt, prices, n, dp));
        else profit = max(prices[ind] + maxProfitUtill(ind+1, 1, cnt-1, prices, n, dp), 
                                0 + maxProfitUtill(ind+1, 0, cnt, prices, n, dp));

        return dp[ind][buy][cnt] = (int)profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return maxProfitUtill(0, 1, 2, prices, n, dp);
    }
};