#include <iostream>
using namespace std;

class Solution {
public:
    int rat(int** a, int m, int n, int i, int j, int** dp) {
        if (i == m - 1 && j == n - 1) {
            return 1;
        }
        if (i >= m || j >= n || a[i][j] == -1) {
            return 0;
        }
        // Check if the result is already computed
        if (dp[i][j] != -5) {
            return dp[i][j];
        }
       
        int right = rat(a, m, n, i, j + 1, dp); 
        int down = rat(a, m, n, i + 1, j, dp);   

        // Store the result in the dp array
        dp[i][j] = right + down;
        return right + down;
    }

    int uniquePaths(int m, int n) {
        // Allocate memory for 2D arrays
        int** grid = new int*[m];
        int** dp = new int*[m];
        for (int i = 0; i < m; ++i) {
            grid[i] = new int[n](); // Initialize with 0
            dp[i] = new int[n];
            fill(dp[i], dp[i] + n, -5); // Initialize with -5
        }

        // Compute the number of unique paths
        int result = rat(grid, m, n, 0, 0, dp);

        // Deallocate memory
        for (int i = 0; i < m; ++i) {
            delete[] grid[i];
            delete[] dp[i];
        }
        delete[] grid;
        delete[] dp;

        return result;
    }
};

