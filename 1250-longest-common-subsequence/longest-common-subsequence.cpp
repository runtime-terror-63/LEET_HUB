class Solution {
public:
/*
    void generateallSub(string &s, int ind, string curr, unordered_set<string> &seq)
    {
    // base case:1
    if (ind == s.length())
    {
        seq.insert(curr);
        return;
    }

    generateallSub(s, ind + 1, curr + s[ind], seq);
    generateallSub(s, ind + 1, curr, seq);
    } */
int rec(string&s1, string&s2, int ind1, int ind2,  int n, int m, vector<vector<int>>&dp){
  if(ind1<0 || ind2<0) return 0;
  if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
  if(s1[ind1]==s2[ind2]) return dp[ind1][ind2] = 1+ rec(s1, s2, ind1-1, ind2-1, n, m, dp);
  return dp[ind1][ind2] = 0+ max(rec(s1, s2, ind1-1, ind2, n, m, dp), rec(s1, s2, ind1, ind2-1, n, m, dp));
}
    int longestCommonSubsequence(string s1, string s2) {
      /*  unordered_set<string> seq1, seq2;
        generateallSub(text1, 0, "", seq1);
        generateallSub(text2, 0, "", seq2);

        int maxLen = 0;
        for (auto it : seq2)
        {
            if (seq1.find(it) != seq1.end())
            {
            maxLen = max(maxLen, (int)it.length());
            }
        }
        return maxLen;  */
         int n = s1.length();
  int m = s2.length();
  vector<vector<int>>dp(n, vector<int>(m, -1));
  return rec(s1, s2, n-1, m-1, n, m, dp);
    }
};