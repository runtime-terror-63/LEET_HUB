class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.size()==0) return nums.size();
        int largest = 1, curr_cnt = 0, lastSmallest = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]-1 == lastSmallest) {
                curr_cnt +=1;
                lastSmallest = nums[i];
            }else if(nums[i] != lastSmallest){
                curr_cnt = 1;
                lastSmallest = nums[i];
            }
            largest = max(largest, curr_cnt);
        }
        return largest;
    }
};