class Solution {
public:
pair<int, int> count(const string& s) {
    int zero = 0, ones = 0;
    for (auto ch : s) {
        if (ch == '0') zero++;
        else ones++;
    }
    return {zero, ones};
}

int fn(int ind, vector<string>& str, int m, int n, vector<vector<vector<int>>>& dp) {
    
    if (ind == str.size()) return 0;

   
    if (dp[ind][m][n] != -1) return dp[ind][m][n];

   
    int not_take = fn(ind + 1, str, m, n, dp);

  
    int take = 0;
    auto [zero, one] = count(str[ind]);
    if (m >= zero && n >= one) {
        take = 1 + fn(ind + 1, str, m - zero, n - one, dp);
    }

  
    return dp[ind][m][n] = max(take, not_take);
}






    int findMaxForm(vector<string>& str, int m, int n) {
         vector<vector<vector<int>>> dp(str.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
    return fn(0, str, m, n, dp);
    }
};