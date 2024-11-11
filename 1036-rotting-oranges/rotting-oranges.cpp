class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
  int m = grid[0].size();
  int frsh_cnt = 0;
  queue<pair<pair<int, int>, int>>q;
  vector<vector<int>>vis(n, vector<int>(m, 0));
  for(int i=0; i<n; i++){
    for(int j = 0; j<m; j++){
      if(grid[i][j]==2){
        q.push({{i, j}, 0});
        vis[i][j] = 2;
      }else vis[i][j] = 0;

      if(grid[i][j]==1) frsh_cnt++;
    }
  }

  int delRow[4] = {-1, 0, +1, 0};
  int delCol[4] = {0, +1, 0, -1};
  int cnt = 0;
  int tm = 0;
  while(!q.empty()){
    int row = q.front().first.first;
    int col = q.front().first.second;
    int time = q.front().second;
    q.pop();
    tm = max(tm, time);
    for(int i = 0; i<4; i++){
      int nr = row + delRow[i];
      int nc = col + delCol[i];

      if(nr>=0 && nr<n && nc>=0 && nc<m && grid[nr][nc]==1 && !vis[nr][nc]){
        vis[nr][nc] = 2;
        q.push({{nr, nc}, time+1});
        cnt++;
      }
    }
  }
        if(cnt==frsh_cnt) return tm;
        else return -1;
    }
};