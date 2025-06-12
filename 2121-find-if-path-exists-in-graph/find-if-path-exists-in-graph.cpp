class Solution {
public:
class DisjointSet{
  vector<int>parent, rank;
  public:
  DisjointSet(int n){
    parent.resize(n+1);
    rank.resize(n+1, 0);
    for(int i=0; i<=n; i++){
      parent[i] = i;
    }
  }

    int findUPar(int node){
      if(node==parent[node]) return node;
      return parent[node] = findUPar(parent[node]);
    }


    void unionByRank(int u, int v){
      int ulp_u = findUPar(u);
      int ulp_v = findUPar(v);

      if(ulp_u==ulp_v) return ;
      if(rank[ulp_u]<rank[ulp_v]){
        parent[ulp_u] = ulp_v;
      }else if(rank[ulp_v]<rank[ulp_u]){
        parent[ulp_v] = ulp_u;
      }else{
        parent[ulp_v] = ulp_u;
        rank[ulp_u]++;
      }
    }


    bool isConnected(int u, int v){
      return findUPar(u) == findUPar(v);
    }
};

bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
  DisjointSet ds(n);

  for(auto it : edges){
    int u = it[0], v = it[1];
    ds.unionByRank(u, v);
  }
  return ds.isConnected(source, destination);
}
};