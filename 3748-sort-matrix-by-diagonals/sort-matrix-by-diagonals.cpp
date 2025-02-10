class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();
  vector<vector<int>>res = grid;
  for(int i=n-1; i>=0; i--){
    int row = i, col = 0;
    vector<int>vec;
    while(row<n && col<n){
      vec.push_back(grid[row][col]);
      row++;
      col++;
    }

    sort(vec.rbegin(), vec.rend());
    row = i, col = 0;
    int ind = 0;
    while(row<n && col<n){
      res[row][col] = vec[ind++];
      row++;
      col++;
    }
  }

  for (int i = 1; i < n; i++) {
    int row = 0, col = i;
    vector<int> vec;
    
    while (row < n && col < n) {
        vec.push_back(grid[row][col]);
        row++;
        col++;
    }

    sort(vec.begin(), vec.end());
    row = 0, col = i;
    int ind = 0;
    while(row<n && col<n){
      res[row][col] = vec[ind++];
      row++;
      col++;
    }
  }
return res;
    }
};