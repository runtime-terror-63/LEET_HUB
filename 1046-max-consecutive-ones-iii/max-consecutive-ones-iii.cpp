class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         int windowStart = 0;
  int zeroCnt = 0;
  int maxWindow = INT_MIN;
  for(auto windowEnd = 0; windowEnd<nums.size(); windowEnd++){
    if(nums[windowEnd]==0) zeroCnt++;
    if(zeroCnt>k){
      if(nums[windowStart]==0) 
      zeroCnt--;
      windowStart++;
    }
    maxWindow = max(maxWindow, windowEnd-windowStart+1);
  }
  return maxWindow;
    }
};