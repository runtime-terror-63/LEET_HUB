class Solution {
public:
void dfs(int n, int m, vector<vector<int>> &vis, vector<vector<char>> &grid, int i, int j)
{
  int delRow[4] = {0, 1, 0, -1};
  int delCol[4] = {-1, 0, +1, 0};

  for (int ind = 0; ind < 4; ind++)
  {
    int ri = i + delRow[ind];
    int ci = j + delCol[ind];


    if (ri >= 0 && ri < n && ci >= 0 && ci < m && !vis[ri][ci] && grid[ri][ci] == '1')
    {
      vis[ri][ci] = 1;
      dfs(n, m, vis, grid, ri, ci);
    }
  }
}

int numIslands(vector<vector<char>> &grid)
{
  int cnt = 0;
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {

      if (!vis[i][j] && grid[i][j] == '1')
      {
        cnt++;
        dfs(n, m, vis, grid, i, j);
      }
    }
  }
  return cnt;
}
};