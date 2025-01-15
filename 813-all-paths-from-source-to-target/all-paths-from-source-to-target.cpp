class Solution {
public:
    void dfs(int node, vector<int>&ans, vector<vector<int>>&ds, int last_path, vector<vector<int>>&adj){
  ans.push_back(node);
  if(node==last_path) ds.push_back(ans);
  else {
    for(auto it :adj[node]){
      dfs(it, ans, ds, last_path, adj);
    }
  }
  ans.pop_back();
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
  vector<int>ans;
  vector<vector<int>>ds;
  dfs(0, ans, ds, graph.size()-1,graph);
  return ds;
}
};