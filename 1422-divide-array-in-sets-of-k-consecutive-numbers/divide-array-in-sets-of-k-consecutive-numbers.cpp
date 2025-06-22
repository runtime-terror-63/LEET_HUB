class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
          unordered_map<int, int>mpp;
  for(auto it : nums) mpp[it]++;
  priority_queue<int, vector<int>, greater<int>>pq;
  for(auto it : mpp)pq.push(it.first);

  while(!pq.empty()){
    int val = pq.top();
    for(int i = val; i<val+k; i++){
      if(mpp[i]==0) return false;
      else mpp[i]--;
      
      while(!pq.empty() && mpp[pq.top()]==0)
       pq.pop();
    }
  }
  return true;
    }
};