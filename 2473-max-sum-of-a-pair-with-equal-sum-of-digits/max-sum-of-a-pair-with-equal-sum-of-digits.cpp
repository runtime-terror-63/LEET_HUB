class Solution {
public:
       // int addDigit(int n){
        /*
        int sum = 0;
        while(n>0){
            int digit = n%10;
            sum += digit;
            n/=10;
        }
        return sum;
        }
        
        int n = nums.size();
        int maxi = -1;
        for(int i=0; i<n-1; i++){

            for(int j = i+1; j<n; j++){
            if(addDigit(nums[i]) == addDigit(nums[j]))
            maxi = max(maxi, nums[i]+nums[j]);
            }
        }
        return maxi;  */

int maximumSum(vector<int>& nums) {
  int n = nums.size();
  int maxSum = -1;
  unordered_map<int, int>mpp;
  for(auto it : nums){
    int sum = 0, temp = it;
    while(temp>0){
      int digit = temp%10;
      sum += digit;
      temp/=10;
    }

    if(mpp.find(sum)!=mpp.end()){
      maxSum = max(maxSum, mpp[sum]+it);
      mpp[sum] = max(mpp[sum], it);
    } else mpp[sum] = it;
  }
  return maxSum;

    }
};