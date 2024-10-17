class Solution {
public:
    void generateAllSub(int ind, string curr, string &s, unordered_map<string, int> &mpp)
{
  if (ind == s.length())
  {
    mpp[curr]++;
    return;
  }

  generateAllSub(ind + 1, curr + s[ind], s, mpp);
  generateAllSub(ind + 1, curr, s, mpp);
}
int findLUSlength(vector<string> &strs)
{
  unordered_map<string, int> mpp;
  for (auto it : strs)
    generateAllSub(0, "", it, mpp);

  int maxLen = -1;
  for (auto &it : mpp)
  {
    if (it.second == 1)
    {
      maxLen = max(maxLen, (int)it.first.length());
    }
  }

  return maxLen > 0 ? maxLen : -1;
}
};