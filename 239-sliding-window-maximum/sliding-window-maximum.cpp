class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        int n = nums.size();
        vector<int> ans;
        int windowStart = 0;
        int maxSum = 0;
        for(int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            while(!q.empty() && q.back() < nums[windowEnd]) 
            q.pop_back(); 
            
            q.push_back(nums[windowEnd]);

            // When the window size is equal to k
            if(windowEnd - windowStart + 1 == k) {
                ans.push_back(q.front()); 
                if(q.front() == nums[windowStart])  q.pop_front();

                windowStart++; 
            }
        }
        return ans;

        return ans;
    }
};