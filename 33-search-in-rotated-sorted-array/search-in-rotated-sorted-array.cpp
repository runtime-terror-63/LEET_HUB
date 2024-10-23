class Solution {
public:
    int binarysearch(vector<int>&arr, int n, int target){
        int low=0, high=n-1;
        while(low<=high){
            int mid = (low+high)>>1;
            if(arr[mid]==target) return mid;
            if(arr[low]<=arr[mid]){
                if(arr[low]<=target && target<=arr[mid])
                   high = mid-1;
                else low = mid+1;
            } else {
                if(arr[mid]<=target && target<=arr[high])
                   low = mid+1;
                else high = mid-1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        return binarysearch(nums, n, target);
    }
};