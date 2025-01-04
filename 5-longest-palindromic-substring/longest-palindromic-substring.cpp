class Solution {
public:
    string longestPalindrome(string s1) {
        string s2 = s1;
        reverse(s2.begin(), s2.end());
        int n = s1.length();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        int maxi = 0, endIndex = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    
                    
                    int originalIndex = i - dp[i][j];
                    if (originalIndex == n - j) { 
                        if (dp[i][j] > maxi) {
                            maxi = dp[i][j];
                            endIndex = i - 1; 
                        }
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        
        return s1.substr(endIndex - maxi + 1, maxi);
    }
};
