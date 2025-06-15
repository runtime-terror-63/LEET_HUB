class Solution {
public:
    class DisjointSet{
  vector<int>parent, rank;
  public:
  DisjointSet(int n){
    parent.resize(n+1);
    rank.resize(n+1, 0);
    for(int i=0; i<n; i++) parent[i] = i;
  }
  
  int findUpar(int node){
      if(node==parent[node]) return node;
      return parent[node] = findUpar(parent[node]);
  }

  void unionByRank(int u, int v){
    int ulp_u = findUpar(u);
    int ulp_v = findUpar(v);

    if(ulp_u==ulp_v)return ;
    if(rank[ulp_u]<rank[ulp_v]){
      parent[ulp_u] = ulp_v;
    }else if(rank[ulp_v]<rank[ulp_u]){
      parent[ulp_v] = ulp_u;
    }else {
      parent[ulp_v] = ulp_u;
      rank[ulp_u]++;
    }
  }
};
int countCompleteComponents(int n, vector<vector<int>>& edges) {
  DisjointSet ds(n);
  for(auto &it : edges){
    ds.unionByRank(it[0], it[1]);
  }

  unordered_map<int, vector<int>>mpp;
  for(int i=0; i<n; i++){
    int val = ds.findUpar(i);
    mpp[val].push_back(i);
  }

  unordered_map<int, int>edgeCount;
  for(auto& it : edges){
    int val = ds.findUpar(it[0]);
    edgeCount[val]++;
  }

  int cnt = 0;
  for(auto &[node, edge] : mpp){
    int k = edge.size();
    int expect = k*(k-1)/2;
    int actual = edgeCount[node];
    if(expect==actual) cnt++;
  }
  return cnt;
    }
};