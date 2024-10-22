class Solution {
public:

    /*
    bool isIncreasing(vector<int> &subsequences)
    {
        int n = subsequences.size();
        for (int i = 1; i < n; i++)
        {
            if (subsequences[i] <= subsequences[i - 1])
            return false;
        }
        return true;
    }
    void generateAllSub(int ind, vector<int> &arr, int n, vector<int> &subsequences, int &maxLen)
    {
    if (ind == n)
    {
            if (isIncreasing(subsequences))
            maxLen = max(maxLen, (int)subsequences.size());

            return;
        }
        subsequences.push_back(arr[ind]);
        generateAllSub(ind + 1, arr, n, subsequences, maxLen);
        subsequences.pop_back();
        generateAllSub(ind + 1, arr, n, subsequences, maxLen);
    } */

    int getAns(vector<int> &arr, int n, int ind, int prevInd, vector<vector<int>> &dp)
{
        if (ind == n)
            return 0;
        // take or nontake
        if (dp[ind][prevInd + 1] != -1)
            return dp[ind][prevInd + 1];

        int take = 0;
        if (prevInd == -1 || arr[ind] > arr[prevInd])
            take = 1 + getAns(arr, n, ind + 1, ind, dp);

        int non_take = 0 + getAns(arr, n, ind + 1, prevInd, dp);

        return dp[ind][prevInd + 1] = max(take, non_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        /*
        int n = nums.size();
        vector<int> subsequences;
        int maxLen = 0;
        generateAllSub(0, nums, n, subsequences, maxLen);
        return maxLen; */

        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return getAns(nums, n, 0, -1, dp);
    }
};