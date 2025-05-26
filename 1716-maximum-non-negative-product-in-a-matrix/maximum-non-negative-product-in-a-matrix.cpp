class Solution {
public:
int mod = 1000000007;
void solve(int i , int j , vector<vector<int>>& grid ,long long curr , long long &ans ,  vector<vector<long long>> &dp){
    if (grid[i][j] == 0) {
        long long num =0;
        ans = max(ans, num);
        dp[i][j] = ans ;
        return;
    }
    curr *= grid[i][j];
    if(i==0 && j==0){
        ans = max(ans , curr) ;
        dp[i][j] = ans ;
        return ;
    }
    if(dp[i][j] != -1)return ;
     if (i>0) solve(i-1, j , grid, curr, ans , dp);
     if (j>0) solve(i , j-1 , grid , curr , ans , dp);
}

    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int n = grid[0].size() ;
        vector<vector<long long>> dp(m , vector<long long> (n , -1)) ;
        long long ans = -1 ;
         solve(m-1 , n-1 , grid , 1 , ans , dp) ;
        return ans%mod ;
    }
};