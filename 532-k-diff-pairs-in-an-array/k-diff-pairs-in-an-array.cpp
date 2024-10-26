class Solution {
public:
int bs(vector<int> &arr, int target, int low, int n)
{
  int high = arr.size() - 1;
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    if (arr[mid] == target)
      return mid;
    else if (arr[mid] < target)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}
int findPairs(vector<int> &arr, int k)
{
    int n = arr.size();
  sort(arr.begin(), arr.end());
  set<pair<int, int>> st;
  for (int i = 0; i < n; i++)
  {
    if (bs(arr, arr[i] + k, i + 1, n) != -1)
      st.insert({arr[i] + k, arr[i]});
  }
  return st.size();
}
   
};