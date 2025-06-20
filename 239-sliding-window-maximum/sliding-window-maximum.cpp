class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  if(nums.empty() || k==0) return {0};
  priority_queue<pair<int, int>>pq; //max heap: {value, ind}
  vector<int>ds;
  int windowStart = 0;
  for(int windowEnd = 0; windowEnd<nums.size(); windowEnd++){
    pq.push({nums[windowEnd], windowEnd});

    if(windowEnd-windowStart+1==k){
      while(!pq.empty() && pq.top().second<windowStart)pq.pop();

      if(!pq.empty()) ds.push_back(pq.top().first);
      windowStart++;
    }
  }
  return ds;
    }
};