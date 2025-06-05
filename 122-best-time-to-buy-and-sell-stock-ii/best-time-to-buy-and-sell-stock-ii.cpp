class Solution {
public:
    int fn(vector<int>& arr, int n, int ind, int buy, vector<vector<int>>&dp) {
    if (ind == n) return 0;
    if(dp[ind][buy]!=-1) return dp[ind][buy];

    long long  profit = 0;
    if (buy) {
        profit = max(-arr[ind] + fn(arr, n, ind + 1, 0, dp),
                     0 + fn(arr, n, ind + 1, 1, dp));
    } else {
        profit = max(arr[ind] + fn(arr, n, ind + 1, 1, dp),
                     0 + fn(arr, n, ind + 1, 0, dp));
    }

    return dp[ind][buy] =  profit;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(), vector<int>(2, -1));
        return fn(prices, prices.size(), 0, 1, dp);
    }
};