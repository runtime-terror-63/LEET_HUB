class Solution {
public:
void dfs(int n, int m, vector<vector<char>>&grid, vector<vector<int>>&vis, int i, int j){
  int delRow[4] = {-1, 0, +1, 0};
  int delCol[4] = {0, +1, 0, -1};

  for(int ind=0; ind<4; ind++){
    int nr = i + delRow[ind];
    int nc = j + delCol[ind];

    if(nr>=0 && nr<n && nc>=0 && nc<m && !vis[nr][nc] && grid[nr][nc]=='1'){
     vis[nr][nc] = 1;
     dfs(n, m, grid, vis, nr, nc);
    }
  }
}
int numIslands(vector<vector<char>> &grid)
{
   int n = grid.size();
  int m = grid[0].size();
  int cnt = 0;
  vector<vector<int>>vis(n, vector<int>(m, 0));
  for(int i = 0; i<n; i++){
    for(int j=0; j<m; j++){
      if(!vis[i][j] && grid[i][j]=='1') {
        
        dfs(n, m, grid, vis, i, j);
        cnt++;
      }
    }
  }
  return cnt;
}
};