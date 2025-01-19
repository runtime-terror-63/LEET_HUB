class Solution {
public:
    long long calc(vector<int>&arr, vector<int>&brr){
        int n = arr.size();
        long long sum = 0;
        for(int i=0; i<n; i++){
            sum += abs(arr[i]-brr[i]);
        }
        return sum;
    }
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        long long a1 = calc(arr, brr);
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());

        long long a2 = calc(arr, brr);

        return min(a1, a2+k);
    }
};