class Solution {
public:

            int lcsUtil(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp)
        {
        if (ind1 == 0 || ind2 == 0)
            return 0;
        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (s1[ind1 - 1] == s2[ind2 - 1])
            return dp[ind1][ind2] = 1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
        return dp[ind1][ind2] = max(lcsUtil(s1, s2, ind1 - 1, ind2, dp), lcsUtil(s1, s2, ind1, ind2 - 1, dp));
        }
    int minInsertions(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());

        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        int res = lcsUtil(s1, s2, n, m, dp);
        return abs(n - res);
    }
};