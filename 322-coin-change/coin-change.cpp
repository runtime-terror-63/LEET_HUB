class Solution {
public:

    int fn(int n, int target, vector<int>&arr, vector<vector<int>>&dp){
  if(n==0){
    if(target%arr[0]==0) return target/arr[0];
    else return 1e9; 
  }

  if(dp[n][target]!=-1) return dp[n][target];
  int notTake = 0 + fn(n-1, target, arr, dp);
  int take = 1e9;
  if(arr[n]<=target) take = 1 + fn(n, target-arr[n], arr, dp);

  return dp[n][target] = min(take, notTake);
}
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n, vector<int>(amount+1, -1));
        int ans = fn(n-1, amount, coins, dp);

        if(ans>=1e9) return -1;
        return ans;
    }
};