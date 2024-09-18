class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        unordered_map<int, int>mpp;
        for(int i = 1; i<n; i++){
            sum = nums[i-1]+nums[i];

            if(mpp.find(sum) != mpp.end()) return true;

            mpp[sum]++;
        }
        return false;
    }
};