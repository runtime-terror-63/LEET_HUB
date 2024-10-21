class Solution {
public:
/*
    void fn(string &s1, string &s2, int ind, string curr, int &cnt)
        {
        if (ind == s1.length())
        {
            if (curr == s2)
            cnt++;
            return;
        }
        fn(s1, s2, ind + 1, curr + s1[ind], cnt);
        fn(s1, s2, ind + 1, curr, cnt);
        } */
const int prime = 1e9 + 7;
int countUtill(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
  if (j < 0)
    return 1;
  if (i < 0)
    return 0;

  if (dp[i + 1][j + 1] != -1)
    return dp[i + 1][j + 1];

  int result = 0;
  if (s1[i] == s2[j])
  {
    result = (countUtill(s1, s2, i - 1, j - 1, dp) +
              countUtill(s1, s2, i - 1, j, dp)) %
             prime;
  }
  else
    result = countUtill(s1, s2, i - 1, j, dp);

  return dp[i + 1][j + 1] = result;
}
    int numDistinct(string s, string t) {
        /*
        int cnt = 0;
        fn(s, t, 0, "", cnt);
        return cnt; */
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
  return countUtill(s, t, n - 1, m - 1, dp);
    }
};