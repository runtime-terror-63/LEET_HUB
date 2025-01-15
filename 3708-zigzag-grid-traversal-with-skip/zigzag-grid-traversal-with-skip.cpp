class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
  int n = grid.size();
  int m = grid[0].size();
  vector<int>ds;

  for(int i =0; i<n; i++){
    if(i%2==0){
      for(int j=0; j<m; j++){
        if(j%2==0) ds.push_back(grid[i][j]);
      }
    }
    else {
      for(int j=m-1; j>=0; j--){
        if(j&1) ds.push_back(grid[i][j]);
      }
    }
  }
  return ds;
}
};