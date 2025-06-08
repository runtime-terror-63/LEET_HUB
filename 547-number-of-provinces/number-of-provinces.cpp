class Solution {
public:
   void dfs(int ind, vector<int>adj[], vector<bool>&vis){
  vis[ind] = true;

  for(auto it : adj[ind]){
    if(!vis[it])
     dfs(it, adj, vis);
  }
}
int findCircleNum(vector<vector<int>>& isConnected) {
  int v = isConnected.size();
  int cnt = 0;
  vector<int>adj[v];

  for(int i=0; i<v; i++){
    for(int j=0; j<v; j++){
      if(isConnected[i][j]==1 ){
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }
  vector<bool>vis(v, false);
  for(int i=0; i<v; i++){
    if(!vis[i]) {
      dfs(i, adj, vis);
      cnt++;
    }
  }
  return cnt;
}
};