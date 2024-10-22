class Solution {
public:
    int maxProfitUtill(int ind, int buy, vector<int>&prices, int n, vector<vector<int>>&dp){
        if(ind==n) return 0;
        long long profit = 0;

        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy) profit = max(-prices[ind]+maxProfitUtill(ind+1, 0, prices, n, dp),  //take
                             0 + maxProfitUtill(ind+1, 1, prices, n, dp)); //not take
        else profit = max(prices[ind]+maxProfitUtill(ind+1, 1, prices, n, dp), 
                           0 + maxProfitUtill(ind+1, 0, prices, n, dp));
        return dp[ind][buy] = (int)profit;
    }
    int maxProfit(vector<int>& prices) {
        /* greedy
        int profit = 0, n = prices.size();
        for(int i=1; i<n; i++){
            if(prices[i]>prices[i-1]) profit+= prices[i]-prices[i-1];
        }
        return profit; */

        //memorization
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return maxProfitUtill(0, 1, prices, n, dp);
    }
};