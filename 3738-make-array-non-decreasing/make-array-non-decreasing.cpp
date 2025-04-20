class Solution {
public:
   int maximumPossibleSize(vector<int>& nums) {
   int cnt = 0, prev = -1;
  for(auto it : nums){
    if(it>=prev){
      prev = it;
      cnt++;
    }
  }
  return cnt;
}
};