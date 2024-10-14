class Solution {
public:
    bool solve(int ind, int target, vector<int>&nums, vector<vector<int>>&dp){
        if(target==0) return true;
        if (ind == 0) return target == nums[ind];
        if(dp[ind][target] !=-1) return dp[ind][target];
        bool non_take = solve(ind-1, target, nums, dp);
        bool take = false;
        if(target>=nums[ind]) take = solve(ind-1, target-nums[ind], nums, dp);

        return dp[ind][target] = take || non_take;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto it : nums)  sum += it;

        if(sum &1) return false;
        int target = sum/2;
        vector<vector<int>>dp(nums.size(), vector<int>(target+1, -1));
        return solve(nums.size()-1, target, nums, dp);
    }
};