class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m, -1));

        queue<pair<pair<int, int>,int>>q;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
            if(grid[i][j]==0){
                q.push({{i, j}, 0});
                vis[i][j] = 0;
            }
            }
        }

        int delRow[4] = {-1, 0, +1, 0};
        int delCol[4] = {0, +1, 0, -1};

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            for(int i=0; i<4; i++){
            int nr = row + delRow[i];
            int nc = col + delCol[i];

            if(nr>=0 && nr<n && nc>=0 && nc<m && 
                vis[nr][nc]==-1){
                    vis[nr][nc] = dist+1;
                    q.push({{nr, nc}, dist+1});
                }
            }
        }
            return vis;
    }
};