class Solution {
public:
bool fn(vector<int>&arr, int mid, int m, int k){
  int n  =arr.size();
  int cnt = 0, noCnt = 0;
  for(int i=0; i<n; i++){
    if(arr[i]<=mid){
      cnt++;
    }else {
      noCnt += (cnt/k);
      cnt = 0;
    }
  }

  noCnt+=(cnt/k);
  return noCnt>=m;
}
int minDays(vector<int>& bloomDay, int m, int k) {
  int low = *min_element(bloomDay.begin(), bloomDay.end());
  int high = *max_element(bloomDay.begin(), bloomDay.end());
  int ans = -1;
  while(low<=high){
    int mid = (low+high)/2;
    if(fn(bloomDay, mid, m, k)){
      ans = mid;
      high = mid-1;
    }else low = mid+1;
  } 
  return ans;
    }
};