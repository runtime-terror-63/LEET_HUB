class Solution {
public:

int fn(int i, int j1, int j2, vector<vector<int>>& arr, vector<vector<vector<int>>>&dp) {
    int n = arr.size();
    int m = arr[0].size();

    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e9;

    if (i == n - 1) {
        if (j1 == j2) return arr[i][j1];
        else return arr[i][j1] + arr[i][j2];
    }

    // int res = 0;
    // if (j1 == j2) res = arr[i][j1];
    // else res = arr[i][j1] + arr[i][j2];


    if(dp[i][j1][j2]!=-1) return dp[i][j1][j2];


    int maxi = INT_MIN;

    for (int di = -1; di <= +1; di++) {
        for (int dj = -1; dj <= +1; dj++) {
            int val = (j1==j2)? arr[i][j1] + fn(i+1, j1+di, j2+dj, arr, dp) : arr[i][j1] + arr[i][j2] + fn(i+1, j1+di, j2+dj, arr, dp);
            maxi = max(maxi, val);
        }
    }

    return dp[i][j1][j2] =  maxi;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return fn(0, 0, m - 1, grid, dp);
    }
};