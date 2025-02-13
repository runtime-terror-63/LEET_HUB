class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
          priority_queue<long long , vector<long long >, greater<long long >>pq;
  for(auto it : nums) pq.push(it);

  long long  cnt = 0;

  while(pq.top()<k){
    long long first = pq.top();
    pq.pop();
    long long sec = pq.top();
    pq.pop();

    long long int sum = min(first, sec) * 2 + max(first, sec);
    pq.push(sum);
    cnt++;
  }

  return (int)cnt;
    }
};