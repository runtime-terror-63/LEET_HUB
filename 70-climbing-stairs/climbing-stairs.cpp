class Solution {
public:
    int fn(int n, vector<int>&dp){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n] = fn(n-1, dp) + fn(n-2, dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return fn(n, dp);
    }
};