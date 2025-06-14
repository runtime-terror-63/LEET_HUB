class Solution {
public:
    int isOk(int i){
  int sum = 0;
  while(i>0){
    int dx = i%10;
    sum += dx;
    i/=10;
  }
  return sum;
}
int smallestIndex(vector<int>& nums) {
  int n = nums.size();
  vector<pair<int, int>>arr;
  for(int i=0; i<n; i++)
    arr.push_back({isOk(nums[i]), i});
    int ans = -1;
    for(auto it : arr){
      if(it.first==it.second){
        ans = it.second;
        break;
      }
    }
    return ans;
    }
};