class Solution {
public:
    int func(int mid, vector<int>& weights){
  int day = 1, load = 0;
  for(auto it : weights){
    if(load + it > mid){
      day++;
      load = 0;
    }
    load += it;
  }
  return day;
}

int shipWithinDays(vector<int>& weights, int days) {
  int n = weights.size();
  int low = *max_element(weights.begin(), weights.end());
  int high = accumulate(weights.begin(), weights.end(), 0);
  int ans = -1;
  while(low<=high){
    int mid = low + (high-low)/2;
    int ele = func(mid, weights);
    if(ele<=days){
      ans = mid;
      high = mid-1;
    }else low = mid+1;
  }
  return ans;
}
};