class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int>pq;
        for(auto it : nums)pq.push(it);

        vector<int>res;
        while(k--){
            res.push_back(pq.top());
            pq.pop();
        }

        int n = res.size();
        return res[n-1];
    }
};