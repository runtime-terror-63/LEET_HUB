class Solution {
public:
    int longestIncrease(vector<int> &arr, int n)
    {
        vector<int> dp(n, 1);
        vector<int> cnt(n, 1);

        int maxi = 1;
        for (int i = 0; i < n; i++)
        {
            for (int prev_ind = 0; prev_ind < i; prev_ind++)
            {
            if (arr[prev_ind] < arr[i] && 1 + dp[prev_ind] > dp[i])
            {
                dp[i] = 1 + dp[prev_ind];
                cnt[i] = cnt[prev_ind];
            }
            else if (arr[prev_ind] < arr[i] && dp[prev_ind] + 1 == dp[i])
                cnt[i] = cnt[i] + cnt[prev_ind];
            }
            maxi = max(maxi, dp[i]);
        }

        int numberOfLIS = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == maxi)
            numberOfLIS += cnt[i];
        }
        return numberOfLIS;
    }
    int findNumberOfLIS(vector<int>& nums) {
        return longestIncrease(nums, nums.size());
    }
};