class Solution {
public:

    void solve(int ind, string s, int len, string temp, vector<string> &ans)
{
  if (ind == len)
  {
    ans.push_back(temp);
    return;
  }

  // digit take
  char ch = s[ind];
  if (isdigit(ch))
  {
    solve(ind + 1, s, len, temp + ch, ans);
  }
  else
  {
    // take
    solve(ind + 1, s, len, temp + ch, ans);

    // not take
    // uppercase -- lowercase
    // lowercase -- uppercase
    if (islower(ch))
    {
      solve(ind + 1, s, len, temp += toupper(ch), ans);
    }
    else
      solve(ind + 1, s, len, temp += tolower(ch), ans);
  }
}
    vector<string> letterCasePermutation(string s) {
        vector<string>ans;
        int len = s.length();
        string temp = "";
        solve(0, s, len, temp, ans);
        return ans;
    }
};