class Solution {
public:
void fn(vector<int>&arr, vector<vector<int>>&ans, vector<int>&ds, int ind){
  ans.push_back(ds);
  for(int i=ind; i<arr.size(); i++){
    if(i!=ind && arr[i]==arr[i-1]) continue;
    ds.push_back(arr[i]);
    fn(arr, ans, ds, i+1);
    ds.pop_back();
  }
}
vector<vector<int>>subsetsWithDup(vector<int>&arr){
        sort(arr.begin(), arr.end());
        vector<vector<int>>ans;
        vector<int>ds;
        fn(arr, ans, ds, 0);
        return ans;
    }
};