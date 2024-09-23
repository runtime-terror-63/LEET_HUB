class Solution {
    bool isValid(long long h, long long m, vector<int> & arr)
    {
        for(long long t: arr)
        {
            auto x = (double)sqrt(m / t * 2 + 0.25) - 0.5;
            h -= floor(x);
            if(h <= 0) return true;
        }
        return false;
    }
public:
    long long minNumberOfSeconds(int H, vector<int>& arr) {
        long long maxi = *(min_element(arr.begin(), arr.end()));
        long long h = H;
        long long l = 1, r = maxi*((long long)h*(h+1)/2);

        while(l < r)
        {
            long long mid = l + (r - l)/2;
            if(isValid(h, mid, arr))
                r = mid;
            else 
                l = mid + 1;
        }
        return r;
    }
};