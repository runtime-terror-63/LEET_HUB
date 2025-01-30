class Solution {
public:
/*
    vector<vector<int>> subArray(vector<vector<int>>&ds, vector<int>&arr){
  int n = arr.size();
  for(int i=0; i<n; i++){
    vector<int>ans;
    for(int j=i; j<n; j++){
      ans.push_back(arr[j]);
      ds.push_back(ans);
    }
  }
  return ds;
}
vector<vector<int>>fn(vector<int>&arr){
  vector<vector<int>>ds;
  subArray(ds, arr);
  return ds;
} */
/*
int subarrayBitwiseORs(vector<int>& arr) {
  vector<vector<int>> res = fn(arr);
  set<int>st;
  int curr_or = 0;
  for(auto it : res){
    for(auto val : it) {
      curr_or |= val;
    }
    st.insert(curr_or);
    curr_or = 0;
  }        
  return st.size();
} */

int fn(unordered_set<int>&st, unordered_set<int>cur, unordered_set<int>prev, vector<int>&arr, int n){
  if(n<0) return st.size();
  cur.insert(arr[n]);

  for(auto i : prev){
    cur.insert(arr[n]|i);
  }
  st.insert(cur.begin(), cur.end());

  return fn(st, unordered_set<int>(), cur, arr, n-1); 
}
int subarrayBitwiseORs(vector<int>& arr) {
  unordered_set<int>st;
  return fn(st, unordered_set<int>(), unordered_set<int>(), arr, arr.size()-1);
}
};