class Solution {
public:
    int bfs(vector<vector<int>>&grid, int i, int j){
  int n = grid.size();
  int m = grid[0].size();
  int maxFish = 0;
  int dx[4] = {-1,0,+1,0};
  int dy[4] = {0,+1,0,-1};
  queue<pair<int, int>>q;
  q.push({i, j});
  maxFish += grid[i][j];
  grid[i][j] = 0;
  while(!q.empty()){
    auto node = q.front();
    int rx = node.first;
    int cx = node.second;
    q.pop();

    for(int i=0; i<4; i++){
      int newr = dx[i] + rx;
      int newc = dy[i] + cx;

      if(newr>=0 && newr<n && newc>=0 && newc<m && grid[newr][newc]>0){
        maxFish += grid[newr][newc];
        grid[newr][newc] = 0;
        q.push({newr, newc});
      }
    }
  }
  return maxFish;
}
int findMaxFish(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();
  int maxFish = 0;
  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(grid[i][j]>0) maxFish = max(maxFish, bfs(grid, i, j));
    }
  }
  return maxFish;
}
};