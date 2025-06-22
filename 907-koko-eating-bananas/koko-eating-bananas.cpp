class Solution {
public:
bool fn(int mid, int h, vector<int>&arr){
  long long ans = 0;
  for(int i=0; i<arr.size(); i++){
    ans += ceil((double)arr[i]/mid);
  }
  return ans<=h;
}
int minEatingSpeed(vector<int>&arr, int h){
  int n = arr.size();
  int low = 1;
  int high = *max_element(arr.begin(), arr.end());
  int ans = -1;
  while(low<=high){
    int mid = low + (high-low)/2;
    if(fn(mid, h, arr)){
      ans = mid;
      high = mid-1;
    }else low = mid+1;
  }
  return ans;
}
};