class Solution {
public:
    bool partitionSubset(int ind, vector<int>& nums, int target, vector<vector<int>>& dp) {
        if (target == 0) return true; 
        if (ind >= nums.size() || target < 0) return false;  
        if (dp[ind][target] != -1) return dp[ind][target];

        bool take = partitionSubset(ind + 1, nums, target - nums[ind], dp);  
        bool nonTake = partitionSubset(ind + 1, nums, target, dp);

        return dp[ind][target] = take || nonTake;
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto it : nums) sum += it;
        if (sum % 2 != 0) return false;

        int target = sum / 2;
        vector<vector<int>> dp(nums.size(), vector<int>(target + 1, -1));
        return partitionSubset(0, nums, target, dp);
    }
};
