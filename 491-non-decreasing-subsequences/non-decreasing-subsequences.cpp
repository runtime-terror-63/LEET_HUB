class Solution {
public:
    void solve(vector<int>&nums, int ind, vector<int>&ds, set<vector<int>>&ans){
  if(ind==nums.size()){
    if(ds.size()>1) ans.insert(ds);
    return;
  }

  if(ds.empty()||nums[ind]>=ds.back()){
    ds.push_back(nums[ind]);
    solve(nums, ind+1, ds, ans);
    ds.pop_back();
  }
  solve(nums, ind+1, ds, ans);
}
vector<vector<int>> findSubsequences(vector<int>& nums) {
  set<vector<int>>ans;
  vector<int>ds;
  solve(nums, 0, ds, ans);
  return vector(ans.begin(), ans.end());
}
};