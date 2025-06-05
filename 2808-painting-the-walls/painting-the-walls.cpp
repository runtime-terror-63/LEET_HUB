class Solution {
public:
    int fn(int i, int n, vector<int>&cost, vector<int>&time, vector<vector<int>>&dp){
        if(n<=0) return 0;
        if(i==cost.size()) return 1e9;
        if(dp[i][n]!=-1) return dp[i][n];
        int take = cost[i] + fn(i+1, n-(time[i]+1), cost, time, dp);
        int notTake = fn(i+1, n, cost, time, dp);
        return dp[i][n] = min(take, notTake);
  }
    int paintWalls(vector<int>& cost, vector<int>& time) {
         vector<vector<int>>dp(501, vector<int>(501, -1));
         return fn(0, cost.size(), cost, time, dp);
    }
};