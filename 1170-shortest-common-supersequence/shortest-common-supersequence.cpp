class Solution {
public:
    int lcs(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp)
{
  if (ind1 == 0 || ind2 == 0)
    return 0;
  if (dp[ind1][ind2] != -1)
    return dp[ind1][ind2];
  if (s1[ind1 - 1] == s2[ind2 - 1])
    return dp[ind1][ind2] = 1 + lcs(s1, s2, ind1 - 1, ind2 - 1, dp);
  else
    return dp[ind1][ind2] = max(lcs(s1, s2, ind1 - 1, ind2, dp), lcs(s1, s2, ind1, ind2 - 1, dp));
}

string SuperseqCommon(string &s1, string &s2, int n, int m, vector<vector<int>> &dp)
{
  int len = dp[n][m];
  int i = n;
  int j = m;
  string ans = "";
  while (i > 0 && j > 0)
  {
    if (s1[i - 1] == s2[j - 1])
    {
      ans += s1[i - 1];
      i--;
      j--;
    }
    else if (dp[i - 1][j] > dp[i][j - 1])
    {
      ans += s1[i - 1];
      i--;
    }
    else
    {
      ans += s2[j - 1];
      j--;
    }
  }

  while (i > 0)
  {
    ans += s1[i - 1];
    i--;
  }
  while (j > 0)
  {
    ans += s2[j - 1];
    j--;
  }

  reverse(ans.begin(), ans.end());
  return ans;
}
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        lcs(s1, s2, n, m, dp);
        return SuperseqCommon(s1, s2, n, m, dp);
    }
};