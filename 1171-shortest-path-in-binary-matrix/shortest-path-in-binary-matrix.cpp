class Solution {
public:
    int dx[8] = {-1, -1, -1,  0, 0, 1, 1, 1};
int dy[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();
  queue<pair<pair<int, int>, int>>q;
  vector<vector<bool>>vis(n, vector<bool>(m, false));

  if(grid[0][0] !=0) return -1;
  q.push({{0, 0}, 1});
  vis[0][0] = true;

  while(!q.empty()){
    int u = q.front().first.first;
    int v = q.front().first.second;
    int step = q.front().second;
    q.pop();
    if(u==n-1 && v==m-1)return step;
    for(int d=0; d<8; d++){
      int nrow = dx[d] + u;
      int ncol = dy[d] + v;
      if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 0 && !vis[nrow][ncol]){
        vis[nrow][ncol] = true;
        q.push({{nrow, ncol}, step+1});
      }
    }
  }
  return -1;
    }
};