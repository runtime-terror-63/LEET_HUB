class Solution {
public:
  const int MOD = 1e9+7;
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        /*        
          int n = nums1.size();

  int total_sum = 0;
  for(int i=0; i<n; i++){
    total_sum += abs(nums1[i] - nums2[i]);
  }

  long long  minSum = total_sum;
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      int ori_Diff = abs(nums1[i] - nums2[i]);
      int new_diff = abs(nums1[j]-nums2[i]);

      long long  diff = total_sum-ori_Diff+new_diff;

      minSum = min(minSum, diff);
    }
  }
  return minSum%MOD;  */

  
        int n = nums1.size();
        
        
        vector<int> sortedNums1 = nums1;
        sort(sortedNums1.begin(), sortedNums1.end());

       
        long totalDiff = 0;
        int maxReduction = 0;

        for (int i = 0; i < n; i++) {
            int originalDiff = abs(nums1[i] - nums2[i]);
            totalDiff = (totalDiff + originalDiff) % MOD;

           
            auto it = lower_bound(sortedNums1.begin(), sortedNums1.end(), nums2[i]);

          
            if (it != sortedNums1.end()) {
                int newDiff = abs(*it - nums2[i]);
                maxReduction = max(maxReduction, originalDiff - newDiff);
            }
           
            if (it != sortedNums1.begin()) {
                --it;
                int newDiff = abs(*it - nums2[i]);
                maxReduction = max(maxReduction, originalDiff - newDiff);
            }
        }

       
        return (totalDiff - maxReduction + MOD) % MOD;
    }
  
    
};