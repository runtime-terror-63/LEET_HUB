class Solution {
public:
int binarySearch(int val, vector<pair<int, int>> &adx)
{
  int ans = -1, low = 0, high = adx.size()-1;
  while (low <= high)
  {
    int mid = (low + high) >> 1;
    if (adx[mid].first >= val)
    {
      ans = adx[mid].second;
      high = mid - 1;
    }
    else
      low = mid + 1;
  }
  return ans;
}
vector<int> findRightInterval(vector<vector<int>> &intervals)
{
   // if(intervals.size()==1) return {-1};

  vector<pair<int, int>> adx;
  for (int i = 0; i < intervals.size(); i++)
  {
    adx.push_back({intervals[i][0], i});
  }

  sort(adx.begin(), adx.end());
  vector<int> ans(intervals.size(), -1);
  int i = 0;
  for (auto it : intervals)
  {
    int val = it[1];
    int ind = binarySearch(val, adx);
    ans[i] = ind;
    i++;
  }
  return ans;
  /*
[[3,4], [2,3], [1,2]]
[[3,0], [2,1], [1,2]] --> sort based on start-> [[1,2], [2,1], [3,0]]
4-> [1, 2, 3] -1
3-> [1, 2, 3]  0
2-> [1, 2, 3]  1
now [-1,0,1]
*/
}
};