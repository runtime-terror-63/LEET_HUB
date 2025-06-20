class Solution {
public:
    int longestOnes(vector<int>& nums, int k) { 
  int n = nums.size();
  int l = 0, r = 0, maxFreq = 0, windowSize = 0;
  int result = 0;
  while(r<n){
    if(nums[r]==1) maxFreq++;
    windowSize = r-l+1;
    int toReplace = windowSize - maxFreq;

    if(toReplace>k){
      if(nums[l]==1) maxFreq--;
      l++;
    }

    result = max(result, r-l+1);
    r++;
  }
  return result;
        
    }
};