class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
  while(low<=high){
    int mid = low + (high-low)/2;
    if(nums[mid]==target) return true;
    if(nums[mid]==nums[low] && nums[mid]==nums[high]){
      low = low+1;
      high = high-1;
      continue;
    }
    else if(nums[mid]>=nums[low]){
      if(nums[mid]>=target && nums[low]<=target) high = mid-1;
      else low = mid+1;
    }else {
      if(nums[mid]<=target && target<=nums[high]) low = mid+1;
      else high = mid-1;
    }
  }
  return false;
    }
};