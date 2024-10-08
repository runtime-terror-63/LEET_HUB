    #include <bits/stdc++.h>
using namespace std;

class Disjointset
{
  vector<int> parent, size;

public:
  Disjointset(int n)
  {
    parent.resize(n);
    size.resize(n, 1);
    for (int i = 0; i < n; i++)
      parent[i] = i;
  }

  int findUPar(int node)
  {
    if (node == parent[node])
      return parent[node];
    return parent[node] = findUPar(parent[node]);
  }

  void unionBySize(int u, int v)
  {
    int root_u = findUPar(u);
    int root_v = findUPar(v);
    if (root_u == root_v)
      return;
    if (size[root_u] < size[root_v])
    {
      parent[root_u] = root_v;
      size[root_v] += size[root_u];
    }
    else
    {
      parent[root_v] = root_u;
      size[root_v] += size[root_u];
    }
  }
};

class Solution {
public:
bool equationsPossible(vector<string> &equations)
{
  Disjointset ds(26);
  for (auto &it : equations)
  {
    // process for all ==
    if (it[1] == '=')
    {
      int var1 = it[0] - 'a';
      int var2 = it[3] - 'a';
      ds.unionBySize(var1, var2);
    }
  }

  for (auto &it : equations)
  {
    // process for all !=
    if (it[1] == '!')
    {
      int var1 = it[0] - 'a';
      int var2 = it[3] - 'a';
      if (ds.findUPar(var1) == ds.findUPar(var2))
        return false;
    }
  }
  return true;
}
};