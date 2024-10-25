class Solution {
public:
    void flip_col(int col, vector<vector<int>>&grid, int n){
        for(int row =0; row<n; row++){
            if(grid[row][col]==0)
              grid[row][col] = 1;
            else 
              grid[row][col] = 0;
        }
    }
    void flip_row(int row, vector<vector<int>>&grid, int m){
        for(int col = 0; col<m; col++){
            if(grid[row][col]==0)
              grid[row][col] = 1;
            else 
              grid[row][col] = 0;
        }
    }

    int value(vector<int>&temp){
        int n = temp.size();
        int val = 1;
        int ans = 0;
        for(int i = n-1; i>=0; i--){
            int bit = temp[i];
            ans += (bit * val);
            val = (val<<1);
        }
        return ans;
    }
    int matrixScore(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        //for all rows.. 1st one is zero then flip this row
        for(int row = 0; row<n; row++){
            if(grid[row][0]==0)
              flip_row(row, grid, m);
        }

        //for all colms  if number of zero > number 1 then flips
        for(int col =0; col<m; col++){
            int zero = 0, ones = 0;
            for(int row=0; row<n; row++){
                if(grid[row][col]==0)
                zero++;
                else ones++;
            }

            if(zero>ones)
               flip_col(col, grid, n);
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            ans += value(grid[i]);
        }
        return ans;
    }
};