class DisjointSet
{
  vector<int> parent, size;

public:
  DisjointSet(int n)
  {
    parent.resize(n + 1);
    size.resize(n + 1, 1);
    for (int i = 0; i <= n; i++) 
      parent[i] = i;
  }

  int findUPar(int node)
  {
    if (parent[node] == node)
      return node;
    return parent[node] = findUPar(parent[node]); 
  }

  bool unionBySize(int u, int v)
  {
    int root_u = findUPar(u);
    int root_v = findUPar(v);

   
    if (root_u == root_v)
      return true;

    
    if (size[root_u] < size[root_v])
    {
      parent[root_u] = root_v;
      size[root_v] += size[root_u];
    }
    else
    {
      parent[root_v] = root_u;
      size[root_u] += size[root_v];
    }
    return false; 
  }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            if (ds.unionBySize(u, v))
            return {u, v};
        }
        return {};
    }
};