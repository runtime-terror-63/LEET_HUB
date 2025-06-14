class Solution {
public:
    int isOk(vector<int>&nums, int mid, int p){
  int n = nums.size();
  int i = 1, cnt = 0;
  while(i<n){
    if(nums[i]-nums[i-1] <=mid){
      cnt++;
      i+=2;
    }else i++;
  }
  return cnt>=p;
}
int minimizeMax(vector<int>& nums, int p) {
  //bs on answer
  int n = nums.size();
  sort(nums.begin(), nums.end());
  int low = 0, high = nums[n-1] - nums[0];
  int ans = -1;
  while(low<=high){
    int mid = (low+high)/2;
    if(isOk(nums, mid, p)){
      ans = mid;
      high = mid-1;
    }else low = mid+1;
  }
  return ans;
    }
};