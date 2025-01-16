class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        for(int i=1; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] <= grid[i-1][j]){
                    int val = grid[i-1][j] - grid[i][j] +1;
                    grid[i][j] += val;
                    cnt  += val;
                }
            }
        }
        return cnt;
    }
};