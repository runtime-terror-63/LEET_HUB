class Solution {
public:
bool bs(vector<int>&mat, int target){
  int n = mat.size();
  int low = 0, high = n;
  while(low<=high){
    int mid = low + (high-low)/2;
    if(mat[mid]==target) return true;
    else if(mat[mid]<target) low = mid+1;
    else high = mid-1;
  }
  return false;
}
bool searchMatrix(vector<vector<int>>&mat, int target){
  int n = mat.size();
  int m = mat[0].size();
  int row = 0, col = m-1;

  while(row<n && col>=0){
    if(mat[row][col]==target) return true;
    else if(mat[row][col]<target) row++;
    else col--;
  }
  return false;
    }
};