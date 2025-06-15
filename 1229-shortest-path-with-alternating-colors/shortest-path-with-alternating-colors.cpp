class Solution {
public:
   int RED = 0, BLUE = 1;
vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
  vector<pair<int, int>>adj[n];
  for(auto& it: redEdges){
    int u = it[0];
    int v = it[1];
    adj[u].push_back({v, RED});
  }
  for(auto& it: blueEdges){
    int u = it[0];
    int v = it[1];
    adj[u].push_back({v, BLUE});
  }
  queue<pair<int, int>>q;
  vector<vector<int>>dist(n, vector<int>(2, 1e9));
  q.push({0, RED});
  q.push({0, BLUE});
  dist[0][RED] = 0;
  dist[0][BLUE] = 0;

  while(!q.empty()){
    auto it = q.front();
    int node = it.first;
    int lastcolor = it.second;
    q.pop();
    for(auto [nei, edgeColor] : adj[node]){
      if(edgeColor==lastcolor) continue;
      if(dist[nei][edgeColor]==1e9){
        dist[nei][edgeColor] = dist[node][lastcolor]+1;
        q.push({nei, edgeColor});
      }
    }
  }

  vector<int>res(n);
  for(int i=0; i<n; i++){
    int data = min(dist[i][RED], dist[i][BLUE]);
    if(data!=1e9) res[i] = data;
    else res[i] = -1;
  }
  return res;
    }
};