class Solution {
public:
    int dx[4] = {-1,0,+1,0};
int dy[4] = {0,+1,0,-1};
queue<pair<int, int>>q;
void dfs(vector<vector<int>>&grid, int i, int j){
  int n = grid.size();
  int m = grid[0].size();
  q.push({i, j});
  grid[i][j] = 2;
  for(int k = 0; k<4; k++){
    int x = dx[k] + i;
    int y = dy[k] + j;

    if(x>=0 && x<n && y>=0 && y<m && grid[x][y]==1) dfs(grid, x, y);
  }
}

int bfs(vector<vector<int>>&grid){
  int n = grid.size();
  int m = grid[0].size();
  int ans = 0;
  while(!q.empty()){
    int size = q.size();
    ans ++;
    while(size--){
      
      int x = q.front().first;
      int y = q.front().second;
      q.pop();

      for(int i=0; i<4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<m){
          if(grid[nx][ny]==0){
            grid[nx][ny] = 2;
            q.push({nx, ny});
          }else if(grid[nx][ny]==1) return ans-1;
        }

      }
    }
  }
  return -1;
}
int shortestBridge(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();
  bool f = false;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(grid[i][j]==1){
        dfs(grid, i, j);
        f = true;
        break;
      }    
    }

    if(f) break;
  }

  return bfs(grid);
}
};