class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        if (k == 0 || nums.empty() || k > nums.size()) 
            return 0;

        long long maxsum = 0;
        long long windowStart = 0;
        long long windowSum = 0;

        for (int windowEnd = 0; windowEnd < nums.size(); windowEnd++) {
            windowSum += nums[windowEnd]; 
            mp[nums[windowEnd]]++;  // Increment count of current element
            
            // Check if we have reached the window size
            if (windowEnd - windowStart + 1 == k) {
               
                if (mp.size() == k) {
                    maxsum = max(maxsum, windowSum);  // Update max sum if all elements are unique
                }

                // Shrink the window from the left
                mp[nums[windowStart]]--;
                windowSum -= nums[windowStart];  
                
                // Remove the element from the map if its count becomes zero
                if (mp[nums[windowStart]] == 0) mp.erase(nums[windowStart]);
                windowStart++;  
            }
        }
        return maxsum;
    }
};
