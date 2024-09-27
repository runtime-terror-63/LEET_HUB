class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        int n = nums.size();
        int windowStart = 0;
        long long pair = 0;
        long long res = 0;
        for(auto windowEnd = 0; windowEnd<n; windowEnd++){
            mpp[nums[windowEnd]]++;

            pair += mpp[nums[windowEnd]]-1;

            while(pair>=k){
                res += (n-windowEnd);

                pair-=mpp[nums[windowStart]]-1;
                mpp[nums[windowStart]]--;
                windowStart++;

            }
        }
        return res;
    }
};