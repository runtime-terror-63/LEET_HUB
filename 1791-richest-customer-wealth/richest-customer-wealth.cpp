class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
          int n = accounts.size();
  int m = accounts[0].size();
  int maxi = -1e9;
  for(int i=0; i<n; i++){
    int sum = 0;
    for(int j=0; j<m; j++){
      sum += accounts[i][j];
    }
    if(sum>maxi) maxi = sum;
  }
  return maxi;
    }
};