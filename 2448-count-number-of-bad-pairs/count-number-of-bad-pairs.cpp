class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        //o(n2)
        /* 
        int len = nums.size();
        long long cnt = 0;
        for(int i = 1; i<len; i++){
          for(int j = 0; j<i; j++){
            if(j-i != nums[j]-nums[i]) cnt++;
          }
        }
        return cnt; */

        //o(n) optimal using hashmap
         unordered_map<int, int> mpp; 
    long long ans = 0; 
    int n = nums.size();
    mpp[0 - nums[0]] = 1;

    for (int i = 1; i < n; i++) {
        int key = i - nums[i]; 

        
        if (mpp.find(key) != mpp.end()) {
            ans += i - mpp[key]; 
        } else {
            ans += i;
        }

       
        mpp[key]++; 
    }

    return ans;
    }
};