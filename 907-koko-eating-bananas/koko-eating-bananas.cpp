class Solution {
public:
    long long  fn(vector<int>&piles, int mid, int h){
  long long  cnt = 0;
  for(auto it : piles){
    cnt += ceil((double)it/(double)mid);
  }
  return cnt;
}

int minEatingSpeed(vector<int>& piles, int h) {
  int low = 1, high = *max_element(piles.begin(), piles.end());
  int ans = -1;
  while(low<=high){
    int mid = (low+high)/2;
    if(fn(piles, mid, h)<=h){
      ans = mid;
      high = mid-1;
    }else low = mid+1;
  }
  return ans;
}
};