class Solution {
public:
long long fn(vector<int>&nums, int li){
  int left = 0, high = nums.size()-1;
  long long cnt = 0;
  while(left<=high){
    if(nums[left]+nums[high]<=li){
      cnt += (high-left);
      left++;
    }else high--;
  }
  return cnt;
}
long long countFairPairs(vector<int>& nums, int lower, int upper) {
  sort(nums.begin(), nums.end());
  return fn(nums, upper) - fn(nums, lower-1);
}
};