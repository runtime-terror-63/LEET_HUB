class Solution {
public:
    double maxProbability(int n, vector<vector<int>> &edges, vector<double> &succProb, int start_node, int end_node)
{
  vector<pair<int, double>> adj[n];
  for (int i = 0; i < edges.size(); i++)
  {
    int u = edges[i][0];
    int v = edges[i][1];
    adj[u].push_back({v, succProb[i]});
    adj[v].push_back({u, succProb[i]});
  }

  //{dist, node}
  priority_queue<pair<double, int>> pq;
  pq.push({1.0, start_node});
  vector<double> dist(n, INT_MIN);
  dist[start_node] = 0;

  while (!pq.empty())
  {
    int node = pq.top().second;
    double wei = pq.top().first;
    pq.pop();

    for (auto it : adj[node])
    {
      int adjNode = it.first;
      double cost = it.second;

      if (wei * cost > dist[adjNode])
      {
        dist[adjNode] = wei * cost;
        pq.push({dist[adjNode], adjNode});
      }
    }
  }
  if (dist[end_node] == INT_MIN)
    return 0.0000;
  return dist[end_node];
}
};