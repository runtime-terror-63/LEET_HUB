class Solution {
public:
    int rec(int ind, vector<vector<int>>&dp, vector<int>&nums, int target, int n){
        if(ind==nums.size()){
            if(target==0) return 1;
            else return 0;
        }

        if(dp[ind][target+1001] !=-1) return dp[ind][target+1001];

        int add = rec(ind+1, dp, nums, target-nums[ind], n);
        int substract = rec(ind+1, dp, nums, target+nums[ind], n);
        return dp[ind][target+1001] = add + substract;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        
        vector<vector<int>>dp(nums.size()+1, vector<int>(4000, -1));

        return rec(0, dp, nums, target, nums.size());
    }
};