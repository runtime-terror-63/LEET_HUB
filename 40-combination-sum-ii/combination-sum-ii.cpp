class Solution {
public:
    void fn(vector<vector<int>>&ans, vector<int>&ds, vector<int>&arr, int target, int ind){
  if(target==0){
    ans.push_back(ds);
    return ;
  }

  for(int i = ind; i<arr.size(); i++){
    if(i>ind && arr[i]==arr[i-1]) continue;

    if(arr[i]>target) break;
    ds.push_back(arr[i]);
    fn(ans, ds, arr, target-arr[i], i+1);
    ds.pop_back();
  }
}
vector<vector<int>>combinationSum2(vector<int>&arr, int target){
  sort(arr.begin(), arr.end());
  vector<vector<int>>ans;
  vector<int>ds;
  fn(ans, ds, arr, target, 0);
  return ans;
    }
};