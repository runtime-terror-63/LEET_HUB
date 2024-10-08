class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads)
{
  // deg array
  vector<int> deg(n, 0);
  // matrix
  vector<vector<bool>> adj(n, vector<bool>(n, false));

  // fill degree
  for (auto &road : roads)
  {
    int u = road[0];
    int v = road[1];
    deg[u]++;
    deg[v]++;
    adj[u][v] = true;
    adj[v][u] = true;
  }

  int maxRank = 0;
  for (int i = 0; i < n; ++i)
  {
    for (int j = i + 1; j < n; ++j)
    {
      int rank = deg[i] + deg[j];

      if (adj[i][j])
      {
        rank--;
      }
      maxRank = max(maxRank, rank);
    }
  }
  return maxRank;
}
};