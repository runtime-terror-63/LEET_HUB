class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size(), maxi = 0;
        for(int i=0; i<n; i++){
            int next  = (i+1) % nums.size();
            //maxEle = abs(nums[i] - nums[next]);
            maxi = max(maxi, abs(nums[i] - nums[next]));
        }
        return maxi;
    }
};