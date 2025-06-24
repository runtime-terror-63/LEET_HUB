class Solution {
public:
void fn(vector<int>&arr, int ind,  int target, vector<vector<int>>&ans, vector<int>&ds){
      if(ind==arr.size()){
    if(target==0){
      ans.push_back(ds);
    }
    return ;
  }
  //pick
  if(arr[ind]<=target){
    ds.push_back(arr[ind]);
    fn(arr, ind, target-arr[ind], ans, ds);
    ds.pop_back();
  }

  //not-pick
  fn(arr, ind+1, target, ans, ds);
}
vector<vector<int>>combinationSum(vector<int>&arr, int target){
        vector<vector<int>>ans;
        vector<int>ds;
        fn(arr, 0, target, ans, ds);
        return ans;
    }
};