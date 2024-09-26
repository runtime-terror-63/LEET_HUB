class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(k==0 || arr.empty()) return 0;
        int sum = 0, cnt = 0;
        int windowStart = 0;
        for(auto windowEnd = 0; windowEnd<arr.size(); windowEnd++){
            sum += arr[windowEnd];

            if (windowEnd - windowStart + 1 == k) {
                if((sum/k)>=threshold) cnt++;


                sum -= arr[windowStart];
                windowStart++;
            }
        }

        return cnt;
    }
};