class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int start = max(0, i-nums[i]);
            for(int j = start; j<=i; j++){
                sum += nums[j];
            }

           // cout<<sum<<endl;
        }
        return sum;
    }
};