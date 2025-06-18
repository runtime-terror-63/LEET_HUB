class Solution {
public:
    long long fn(vector<int>&nums, int mid, int threshold){
    long long cnt = 0;
    for(int i=0; i<nums.size(); i++){
        cnt += ceil((double)nums[i]/mid);
    }
    return cnt<=threshold;
}

int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(), nums.end());
        int ans = -1;
        while(low<=high){
            int mid = (low+high)/2;
            if(fn(nums, mid, threshold)){
            ans = mid;
            high = mid-1;
            }else low = mid+1;
        }
        return ans;
    }
};