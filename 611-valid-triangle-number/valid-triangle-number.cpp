class Solution {
public:
    int binarySearch(vector<int>& nums, int l, int r, int target) {
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return r;  
    }

    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        
        
        sort(nums.begin(), nums.end());
        
       
        int i = 0;
        while (i < n - 2) {
            int j = i + 1;
            while (j < n - 1) {
                int sum = nums[i] + nums[j];
                
                
                int k = binarySearch(nums, j + 1, n - 1, sum);
                
                if (k > j) {
                    cnt += (k - j);  
                }
                
                j++;  
            }
            i++;  
        }
        
        return cnt; 
    }
};
