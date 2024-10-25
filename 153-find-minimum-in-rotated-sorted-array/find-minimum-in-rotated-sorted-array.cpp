class Solution {
public:
    int findMin(vector<int>& nums) {
        int mini = 1e9;
        int low = 0, high = nums.size()-1;
        while(low<=high){
            int mid = (low+high)>>1;
            if(nums[low]<=nums[mid]){
                mini = min(mini, nums[low]);
                low = mid+1;
            }else{
                mini = min(mini, nums[mid]);
                high = mid-1;
            }
        }
        return mini;
    }
};