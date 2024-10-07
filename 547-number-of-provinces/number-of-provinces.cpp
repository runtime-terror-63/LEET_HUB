class Solution {
public:

class DisjointSet
{
  vector<int> parent, size;

public:
  DisjointSet(int n)
  {
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  int findUPar(int node)
  {
    if (node == parent[node])
      return node;
    return parent[node] = findUPar(parent[node]);
  }

  void unionBySize(int u, int v)
  {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v)
      return;
    if (size[ulp_u] < size[ulp_v])
    {
      parent[ulp_u] = ulp_v;
      size[ulp_v] += size[ulp_u];
    }
    else
    {
      parent[ulp_v] = ulp_u;
      size[ulp_v] += size[ulp_u];
    }
  }
};
/*
    void dfs(int ind, vector<int>adj[], vector<int>&vis){
        vis[ind] = 1;
        for(auto it : adj[ind]){
            if(!vis[it]) dfs(it, adj, vis);
        }
    }
    */
    int findCircleNum(vector<vector<int>>& adj) {
        /*
        int v = isConnected.size();
        vector<int>visited(v, 0);
        vector<int>ans[v];
        for(int i = 0; i<v; i++){
            for(int j = 0; j<v; j++){
                if(isConnected[i][j]==1 && i!=j){
                    ans[i].push_back(j);
                    ans[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i<v; i++){
            if(!visited[i]){
                dfs(i, ans, visited);
                cnt++;
            }
        }
        return cnt; */

 int v = adj.size();
  DisjointSet ds(v);
  for (int i = 0; i < v; i++)
  {
    for (int j = 0; j < v; j++)
    {
      if (adj[i][j] == 1)
        ds.unionBySize(i, j);
    }
  }

  int cnt_provinces = 0;
  for (int i = 0; i < v; i++)
  {
    if (ds.findUPar(i) == i)
      cnt_provinces++;
  }
  return cnt_provinces;
    }
};