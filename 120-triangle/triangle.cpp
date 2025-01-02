class Solution {
public:
    int fn(int i, int j, vector<vector<int>>& dp, vector<vector<int>>& triangle) {
        int n = triangle.size();
        if (i == n - 1) return triangle[i][j]; // Base case
        
        if (dp[i][j] != -1) return dp[i][j]; // Use memoized result
        
        int down = triangle[i][j] + fn(i + 1, j, dp, triangle); 
        int right_down = triangle[i][j] + fn(i + 1, j + 1, dp, triangle); 

        return dp[i][j] = min(down, right_down);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1)); // Match triangle dimensions
        return fn(0, 0, dp, triangle); // Start at the top
    }
};
