class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
          int n = nums.size(), ind = -1, mini = 1e9;
 for(int i=0; i<n; i++){
  int sum = 0;
  for(int j=i; j<n; j++){
    sum += nums[j];
    ind = j-i+1;
    if(sum>0 && ind>=l && ind<=r) mini = min(mini, sum);
  }
 }

 if(mini==1e9) return -1;
 return mini;
    }
};