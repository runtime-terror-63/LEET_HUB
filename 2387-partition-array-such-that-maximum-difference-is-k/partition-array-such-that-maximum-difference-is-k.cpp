class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
  int n = nums.size();
  int start = nums[0];
  int cnt = 0;
  for(int i=0; i<n; i++){
    if(nums[i]-start>k){
      cnt++;
      start = nums[i];
     // cout<<"cnt-> "<<cnt<<endl;
      //cout<<start<<endl;
    }
  }
  return cnt+1;
    }
};