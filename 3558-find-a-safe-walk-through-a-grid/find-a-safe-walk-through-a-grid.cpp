#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
  int m = grid[0].size();
  int delRow[4] = {0, -1, 0, +1};
  int delCol[4] = {-1, 0, +1, 0};

  vector<vector<int>> visited(n, vector<int>(m, INT_MIN));
  priority_queue<tuple<int, int, int>> pq;
  pq.push({0, 0, health-grid[0][0]});
  visited[0][0] = health - grid[0][0];
  while (!pq.empty())
  {
    auto it = pq.top();
    int row = get<0>(it);
    int col = get<1>(it);
    int currhealth = get<2>(it);
    pq.pop();

    if (row == n - 1 && col == m - 1 && currhealth >= 1)
      return true;
    for (int i = 0; i < 4; i++)
    {
      int nr = row + delRow[i];
      int nc = col + delCol[i];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m)
      {
        if (visited[nr][nc] < currhealth - grid[nr][nc])
        {
          visited[nr][nc] =  currhealth - grid[nr][nc];
          pq.push({nr, nc, currhealth-grid[nr][nc]});
        }
      }
    }
  }
  return false;
    }
};
