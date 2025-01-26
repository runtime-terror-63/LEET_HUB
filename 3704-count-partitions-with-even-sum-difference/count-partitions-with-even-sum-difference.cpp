class Solution {
public:
    int countPartitions(vector<int>& nums) {
          int n = nums.size();
  int sum = 0;
  for(int i=0; i<n; i++)  
    sum += nums[i];
  vector<int>presum(n-1);
  presum[0] = nums[0];
  for(int i=1; i<n-1; i++)
   presum[i] = presum[i-1] + nums[i];
  vector<int>ans;
  for(int i=0; i<presum.size(); i++){
    int x = sum - presum[i];
    ans.push_back(presum[i]-x);
  }
  int cnt = 0;
  for(auto it : ans){
    if(it%2==0) cnt++;
  }

return cnt;
    }
};