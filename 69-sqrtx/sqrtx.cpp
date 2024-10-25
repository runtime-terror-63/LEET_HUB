class Solution {
public:
    int mySqrt(int x) {
        long long low = 1, high = x, ans = 0;
        while(low<=high){
            long long  mid = (low+high)>>1;
            if(mid*mid<=(long long)x) {
                ans = mid;
                low = mid+1;
            }
            else high = mid-1;
        }
        return (int)ans;
    }
};