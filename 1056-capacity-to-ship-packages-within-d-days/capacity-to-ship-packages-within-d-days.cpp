class Solution {
public:
    int func(vector<int>&arr, int mid, int n, int days){
   int sum=0, totalcnt = 1;
  for(int i=0; i<n; i++){
    if(sum+arr[i]>mid){
      totalcnt++;
      sum = arr[i];
    }else sum += arr[i];
  }
  return totalcnt;
}
int minDays(vector<int>&arr, int n, int days){
  int low = *max_element(arr.begin(), arr.end());
  int high = accumulate(arr.begin(), arr.end(), 0);
  int ans = 0;
  while(low<=high){
    int mid = (low+high)>>1;
    if(func(arr, mid, n, days)<=days){
      ans = mid;
      high = mid-1;
    }else low = mid+1;
  }
  return ans;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        return minDays(weights,n, days);
    }
};