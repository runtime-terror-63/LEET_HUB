class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        map<int, int>mpp;
        for(auto it : banned) mpp[it]++;
        int cnt = 0, sme = 0;
        for(int i = 1; i<=n; i++){
            if((mpp.find(i)==mpp.end() ) and ((sme + i) <= maxSum)){
                cnt ++;
                sme += i;
            }
        }
        return cnt;
    }
};