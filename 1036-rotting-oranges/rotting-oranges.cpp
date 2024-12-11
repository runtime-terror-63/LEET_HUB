class Solution {
public:
int orangesRotting(vector<vector<int>> &grid)
{
  int n = grid.size();
  int m = grid[0].size();
  vector<vector<int>> vis(n, vector<int>(m, 0));
  queue<pair<pair<int, int>, int>> q;
  int frsh_cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (grid[i][j] == 2)
      {
        q.push({{i, j}, 0});
        vis[i][j] = 2;
      }
      else
        vis[i][j] = 0;

      if (grid[i][j] == 1)
        frsh_cnt++;
    }
  }

  int delrow[] = {-1, 0, +1, 0};
  int delcol[] = {0, +1, 0, -1};
  int cnt = 0;
  int tm = 0;
  while (!q.empty())
  {
    int r = q.front().first.first;
    int c = q.front().first.second;
    int time = q.front().second;
    q.pop();
    tm = max(tm, time);

    for (int i = 0; i < 4; i++)
    {
      int nrow = r + delrow[i];
      int ncol = c + delcol[i];

      if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
      {
        vis[nrow][ncol] = 2;
        q.push({{nrow, ncol}, time + 1});
        cnt++;
      }
    }
  }

  if (cnt != frsh_cnt)
    return -1;
  return tm;
}
};