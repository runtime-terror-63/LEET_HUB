class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = INT_MIN;
        int zero_cnt = 0;
        int windowStart = 0;
        int n = nums.size();
        for(auto windowEnd = 0; windowEnd<n; windowEnd++){
            if(nums[windowEnd]==0) zero_cnt++;

            if(zero_cnt>k){
                if(nums[windowStart]==0) zero_cnt--;

                windowStart++;
            }

            maxLen = max(maxLen, windowEnd-windowStart+1);
        }
        return maxLen;
    }
};