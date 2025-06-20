class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
          int n = nums.size();
  int i=0, j=0, sum=0;
  int mini = 1e9;
  while(j<n){
    sum += nums[j];
    if(sum>=target){
      while(sum>=target){
        mini = min(mini, j-i+1);
        sum-=nums[i];
        i++;
      }
    }
    j++;
  }
  if(mini==1e9) return 0;
  return mini;
    }
};