class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
  int n = nums.size();
  unordered_map<int, int>mpp;
  for(int i=0; i<n-1; i++){
    for(int j=i+1; j<n; j++){
      int product = nums[i] * nums[j];
      mpp[product]++;
    }
  }

  //for(auto it : mpp) cout<<it.first<<" "<<it.second<<endl;
  int cnt = 0;
  for(auto it : mpp){
    if(it.second>1) cnt+= (it.second * (it.second-1))/2;
  }

  return cnt*8;
  }


};