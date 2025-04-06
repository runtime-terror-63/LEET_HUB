class Solution {
public:
    long long func(vector<int> &arr, int n, int mid, int h)
{
  long long total = 0;
  for (int i = 0; i < n; i++)
  {
    total += ceil((double)(arr[i]) / (double)(mid));
  }
  return total;
}
int findAns(vector<int> &arr, int n, int h)
{
  int low = 1;
  int high = *max_element(arr.begin(), arr.end());
  int ans = INT_MAX;
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    long long  ele = func(arr, n, mid, h);
    if (ele <= h)
    {
      ans = min(ans, mid);
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  return ans;
}
int minEatingSpeed(vector<int> &piles, int h)
{
  int n = piles.size();
  return findAns(piles, n, h);
}
};