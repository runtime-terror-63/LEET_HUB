class Solution {
public:
    int maxSum(vector<int>& nums) {
  unordered_set<int>st;
  for(auto it : nums)st.insert(it);
  //for(auto it : st) cout<<it<<" ";

  int maxi = 0;
  for(auto it : st){
      if(it>0) maxi += it;

  }

  if(maxi==0){
    maxi = *max_element(nums.begin(), nums.end());
 }
  return maxi;
    }
};