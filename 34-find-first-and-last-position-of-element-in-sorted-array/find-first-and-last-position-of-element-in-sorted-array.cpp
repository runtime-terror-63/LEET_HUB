class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
          int low = 0, high = nums.size() - 1, ans =-1;
  vector<int> ds;
  while (low <= high)
  {
    int mid = low + (high - low) / 2;
    if (nums[mid] >= target)
    {
      ans = mid;
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  if(ans != -1 && nums[ans]==target)
  ds.push_back(ans);
  else return {-1, -1};


  int low2 = 0, high2 = nums.size() - 1, ans2 = -1;
  while (low2 <= high2)
  {
    int mid = low2 + (high2 - low2) / 2;
    if (nums[mid] > target)
    {
      high2 = mid - 1;
    }
    else{
      if(nums[mid]==target) ans2 = mid;
      low2 = mid + 1;
    }
  }
 if (ans2 != -1 && nums[ans2] == target)
            ds.push_back(ans2);
        else
            ds.push_back(ans);
  return ds;
    }
};