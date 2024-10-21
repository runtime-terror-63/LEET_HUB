class Solution {
public:
bool isAllStars(string &s1, int i)
{
  for (int j = 0; j <= i; j++)
  {
    if (s1[j] != '*')
      return false;
  }
  return true;
}
/*
bool wildcardmatch(string &s1, string &s2, int i, int j)
{
  if (i < 0 && j < 0)
    return true;
  if (i < 0 && j >= 0)
    return false;
  if (j < 0 && i >= 0)
    return isAllStars(s1, i);

  if (s1[i] == s2[j] || s1[i] == '?')
    return wildcardmatch(s1, s2, i - 1, j - 1);
  else
  {
    if (s1[i] == '*')
      return wildcardmatch(s1, s2, i - 1, j) || wildcardmatch(s1, s2, i, j - 1);
    else
      return false;
  }
}  */

bool wildcardMatching(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
  if (i < 0 && j < 0)
    return true;
  if (i < 0 && j >= 0)
    return false;
  if (j < 0 && i >= 0)
    return isAllStars(s1, i);

  if (dp[i][j] != -1)
    return dp[i][j];
  if (s1[i] == s2[j] || s1[i] == '?')
    return dp[i][j] = wildcardMatching(s1, s2, i - 1, j - 1, dp);
  else
  {
    if (s1[i] == '*')
      return dp[i][j] = wildcardMatching(s1, s2, i - 1, j, dp) || wildcardMatching(s1, s2, i, j - 1, dp);
    else
      return false;
  }
}
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>> dp(m + 1, vector<int>(n+1, -1));

        return wildcardMatching(p, s, m - 1, n - 1, dp);
    }
};