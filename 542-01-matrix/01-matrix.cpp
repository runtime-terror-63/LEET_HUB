class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> ans(n, vector<int>(m, -1)); 
        for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {  
                q.push({0, {i, j}});
                ans[i][j] = 0;  
            }
        }
    }
        
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, 1, -1};
        
        //bfs
        while(!q.empty()){
            int dis = q.front().first;
            int row = q.front().second.first;
            int col = q.front().second.second;
            q.pop();
            
            for(int i = 0; i<4; i++){
                int nrow = row+ delrow[i];
                int ncol = col+ delcol[i];
                
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==-1){
                    q.push({dis + 1, {nrow, ncol}});
                    ans[nrow][ncol] = dis+1;
                }
            }
            
        }
        return ans;
    }
};