class Solution {
public:
    vector<vector<vector<int>>>dp;
    int mini(char &a,char &b){
        int diff=abs(a-b);
        return min(diff,26-diff);
    }
    int solve(int i,int j,string &s,string &r,int k){
        if(i+j>=s.size()) return 0;
        if(s.size()-1-i==j) return 1;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int ans=max(solve(i+1,j,s,r,k),solve(i,j+1,s,r,k));
        int c=mini(s[i],r[j]);
        int op3=0;
        if(c<=k){
            ans=max(ans,2+solve(i+1,j+1,s,r,k-c));
        }
        return dp[i][j][k]=ans;
    }
    int longestPalindromicSubsequence(string s, int k) {
        int n=s.size();
        string r=s;
        reverse(r.begin(),r.end());
        dp.resize(n,vector<vector<int>>(n+1,vector<int>(k+1,-1)));
        return solve(0,0,s,r,k);
    }
};