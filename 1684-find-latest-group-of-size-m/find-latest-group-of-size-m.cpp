class Solution {
public:
    int findLatestStep(vector<int>& arr, int m) {
        int n = arr.size(), ans = -1;
        vector<int>len(n+2, 0), cnt(n+1, 0);
        for(int i = 0; i<n; i++){
            int a = arr[i], low = len[a-1], high = len[a+1];
            int sum = low+high +1;
            len[a-low] = len[a+high] = sum;
            cnt[low]--;
            cnt[high]--;
            cnt[sum]++;
            if(cnt[m]>0) ans = i+1;
        }
        return ans;
    }
};