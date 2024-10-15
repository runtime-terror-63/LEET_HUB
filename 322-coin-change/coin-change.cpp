class Solution {
public:
    
    int fn(int ind, vector<int>&arr, int target, vector<vector<int>>&dp){
        //Base Case:
        if(ind==0){
            if(target%arr[0]==0) return target/arr[0];
            else return 1e9;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int non_take = 0 + fn(ind-1, arr, target, dp);
        int take = 1e9;
        if(target>=arr[ind]) take =  1 + fn(ind, arr, target-arr[ind], dp);

        return dp[ind][target] = min(take, non_take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size(), vector<int>(amount+1, -1));
        int ans = fn(coins.size()-1, coins, amount, dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};