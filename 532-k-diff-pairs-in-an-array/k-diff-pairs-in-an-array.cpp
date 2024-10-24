class Solution {
public:
    int bs(vector<int> &nums, int low, int j)
{
  int high = nums.size() - 1;
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    if (nums[mid] == j)
      return mid;
    else if (nums[mid] < j)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int findPairs(vector<int> &nums, int k)
{
  sort(nums.begin(), nums.end());
  int n = nums.size();
  set<pair<int, int>> st;
  for (int i = 0; i < n; i++)
  {
    if (bs(nums, i + 1, nums[i] + k) != -1)
      st.insert({nums[i], nums[i] + k});
  }
  return st.size();
}
};