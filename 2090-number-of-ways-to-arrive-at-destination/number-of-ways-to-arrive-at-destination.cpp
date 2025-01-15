class Solution {
public:
#define ll long long
int MOD = 1e9+7;
int countPaths(int n, vector<vector<int>>& roads) {
  ll src = 0;
 vector<pair<ll, ll>>adj[n];
  for(auto it : roads){
    int u = it[0];
    int v = it[1];
    int wt = it[2];
    adj[u].push_back({v, wt});
    adj[v].push_back({u, wt});
  }

  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;
  //dist, node;
  pq.push({0, src});
  vector<ll>dist(n, LLONG_MAX), ways(n, 0);
  dist[src] = 0;
  ways[src] = 1;

  while(!pq.empty()){
    ll dis = pq.top().first;
    ll node = pq.top().second;
    pq.pop();

    for(auto it : adj[node]){
      auto nei = it.first;
      auto wt = it.second;

      if(wt+dis<dist[nei]){
        dist[nei] = wt+dis;
        pq.push({dist[nei], nei});
        ways[nei] = ways[node];
      }else if(wt+dis == dist[nei])
       ways[nei] = (ways[node]+ways[nei])%MOD;
    }
  }

  return ways[n-1]%MOD;
}
};