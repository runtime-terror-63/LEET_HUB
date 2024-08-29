class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        int maxi = INT_MIN;
        mpp[0] = 1;
        int prefSum = 0, cnt = 0;
       // for(int j = 0; j<nums.size(); j++){
        for(int i = 0; i<nums.size(); i++){
            prefSum += nums[i];
             int mod = (prefSum%k  -  k) % k;
            cnt += mpp[mod];
            mpp[mod]++;
        }
    //    maxi = max(maxi, cnt);
   //  }
        return cnt;
    }
};