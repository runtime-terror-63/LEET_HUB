class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        /*
        int n = arr.size();
        vector<int>ds;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j = i; j<n; j++){
            sum += arr[j];
            ds.push_back(sum);
            }
        }

        int cnt = 0;

        for(auto it : ds) {
            if(it&1) cnt++;
        }
        return cnt; */
        const int MOD = 1e9+7;
        int evenCnt = 1, oddCnt = 0;
        int preSum = 0;
        int res = 0;
        for(int i = 0; i<arr.size(); i++){
            preSum += arr[i];

            if(preSum%2==0){
            evenCnt++;
            res = (res +oddCnt)%MOD;
            } else {
            oddCnt++;
            res = (res+evenCnt)%MOD;
            }
        }

        return res%MOD;;
    }
};