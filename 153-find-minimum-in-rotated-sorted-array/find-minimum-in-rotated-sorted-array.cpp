class Solution {
public:
    int findMin(vector<int>& nums) {
          int low = 0, high = nums.size()-1, mini = 1e9;
  while(low<=high){
    int mid = low + (high-low)/2;
    if(nums[mid]>=nums[low]){
      mini = min(mini, nums[low]);
      low = mid+1;
    }else {
      mini = min(mini, nums[mid]);
      high = mid-1;
    }
  }
  return mini;
    }
};