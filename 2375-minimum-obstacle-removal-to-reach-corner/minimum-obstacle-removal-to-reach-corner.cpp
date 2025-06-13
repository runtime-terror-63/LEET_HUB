class Solution {
public:
    int dx[4] = {-1, +1, 0, 0};
int dy[4] = {0, 0, -1, +1};

int minimumObstacles(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();
  vector<int> dist(n * m, 1e9);
  queue<pair<int, int>> q;
  q.push({0, 0});
  dist[0] = 0;

  while (!q.empty()) {
    int r = q.front().first;
    int c = q.front().second;
    q.pop();
    int cost = r * m + c;

    for (int i = 0; i < 4; i++) {
      int nr = r + dx[i];
      int nc = c + dy[i];
      if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
        int nextNode = nr * m + nc;
        int newCost = dist[cost] + grid[nr][nc];
        if (newCost < dist[nextNode]) {
          dist[nextNode] = newCost;
            q.push({nr, nc});
        }
      }
    }
  }

  return dist[n * m - 1];
}
};