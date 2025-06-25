class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
          set<int>ans;
  int n = nums.size();
  for(int i=0; i<n; i++){
    for(int j = 0; j<n; j++){
      if(nums[i]==key){
        if(abs(j-i)<=k) ans.insert(j);
      }
    }
  } 
  vector<int>ds(ans.begin(), ans.end());
  return ds;
    }
};