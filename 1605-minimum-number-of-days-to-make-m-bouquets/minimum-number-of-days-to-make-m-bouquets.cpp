class Solution {
public:
    bool func(vector<int> &arr, int n, int m, int mid, int k)
{
  int l = 0, cnt = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] <= mid)
    {
      l++;
      if (l == k){
        cnt++;
        l=0;
      }
    }
    else
      l = 0;
  }

  if (cnt >= m)
    return true;
  return false;
}
int bs(vector<int> &arr, int n, int m, int k)
{
  int low = *min_element(arr.begin(), arr.end());
  int high = *max_element(arr.begin(), arr.end());
  int ans = 0;
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    if (func(arr, n, m, mid, k))
    {
      ans = mid;
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
 // cout<<ans<<endl;
  return ans;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int ans = bs(bloomDay, n, m, k); 
        if(ans==0) return -1;
        else return ans;
    }
};