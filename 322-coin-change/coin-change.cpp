class Solution {
public:
    
int fn(int ind, vector<int>&coins, vector<vector<int>>&dp, int amount, int n){
  if(ind==0){
    if(amount%coins[0]==0) return amount/coins[0];
    else return 1e9;
  }
  //take not_take
  if(dp[ind][amount]!=-1) return dp[ind][amount];

  int not_take = 0 + fn(ind-1, coins, dp, amount, n);
  int take = 1e9;
  if(amount>=coins[ind]) take = 1 + fn(ind, coins, dp, amount-coins[ind], n);

  return dp[ind][amount] =  min(take, not_take);
}
int coinChange(vector<int>& coins, int amount) {
  int n = coins.size();
  vector<vector<int>>dp(n, vector<int>(amount+1, -1));
  int ans =  fn(n-1, coins, dp, amount, n);
  if(ans>=1e9) return -1;
  return ans;
}
};