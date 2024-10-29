class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        if (nums.empty()) return 0;
        int windowStart = 0;
        long long  maxSum = 0;
        long long  windowSum = 0;
        map<int, int> mpp;
        for (auto windowEnd = 0; windowEnd < nums.size(); windowEnd++)
        {
            windowSum += nums[windowEnd];
            mpp[nums[windowEnd]]++;
            if (windowEnd - windowStart + 1 == k)
            {
            // cout << " step-> " << mpp.size() << endl;
            if (mpp.size()>=m)
                maxSum = max(maxSum, windowSum);
            mpp[nums[windowStart]]--;
            if(mpp[nums[windowStart]]==0) mpp.erase(nums[windowStart]);
            windowSum -= nums[windowStart];
            windowStart++;
            }
        }
        return maxSum;
    }
};