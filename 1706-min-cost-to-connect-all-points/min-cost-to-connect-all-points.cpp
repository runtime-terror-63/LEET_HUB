class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
          int n = points.size();
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  pq.push({0, 0});
  vector<int> vis(n, 0);
  int sum = 0;
  int cnt = 0;
  while (!pq.empty() && cnt < n)
  {
    auto it = pq.top();
    pq.pop();
    int wt = it.first;
    int node = it.second;
    if (vis[node])
      continue;
    vis[node] = 1;
    sum += wt;
    cnt++;
    for (int i = 0; i < n; i++)
    {
      if (!vis[i])
      {
        int cost = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
        pq.push({cost, i});
      }
    }
  }
  return sum;
    }
};