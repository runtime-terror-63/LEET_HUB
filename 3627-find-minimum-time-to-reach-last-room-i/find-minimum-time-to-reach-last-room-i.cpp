class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
  int delRow[4] = {0, +1, 0, -1};
  int delCol[4] = {+1, 0, -1, 0};

  int n = moveTime.size();
  int m = moveTime[0].size();

  vector<vector<int>> distTo(n, vector<int>(m, INT_MAX));
  distTo[0][0] = 0;

  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
  pq.push({0, 0, 0});

  while (!pq.empty())
  {
    auto it = pq.top();
    pq.pop();
    int time = get<0>(it);
    int row = get<1>(it);
    int col = get<2>(it);

    if (row == n - 1 && col == m - 1)
      return time;
    for (int i = 0; i < 4; i++)
    {
      int nr = row + delRow[i];
      int nc = col + delCol[i];

      if (nr >= 0 && nr < n && nc >= 0 && nc < m)
      {
        int newTime = max(time, moveTime[nr][nc]) + 1;
        if (newTime < distTo[nr][nc])
        {
          distTo[nr][nc] = newTime;
          pq.push({newTime, nr, nc});
        }
      }
    }
  }
  return -1;
    }
};