class Solution {
public:
    const int MOD = 1e9+7;
int dp[26][100005];
int dfs(char ch, int t){
  if(t==0) return 1;
  if(dp[ch][t]!=-1) return dp[ch][t];

  if(ch==25){
    dp[ch][t] = (dfs(0, t-1) + dfs(1, t-1))%MOD;
  }else {
    dp[ch][t] = dfs(ch+1, t-1);
  }
    return dp[ch][t];
}
int lengthAfterTransformations(string s, int t) {
  memset(dp, -1, sizeof(dp));

  long long total = 0;
  for(auto c : s){
    total = (total+ dfs(c-'a', t))%MOD;
  }
  return total;
    }
};