class Solution {
public:
    int solve(vector<int>&dp, string &s, int indx){
        if(indx==s.size()) return 0;

        if(dp[indx]!=-1) return dp[indx];
        unordered_map<char, int>mpp;
        int ans = 1e9, cnt = 1e9;

        for(int i = indx; i<s.length(); i++){
            mpp[s[i]]++;
            int prevFreq = -1;
            bool check = true;

            for(auto it : mpp){
                if(prevFreq == -1) prevFreq = it.second;

                else if(prevFreq != it.second) {
                    check = false;
                    break;
                }
            }



            if(check) {
                cnt = 1 + solve(dp, s, i+1);
                ans  = min(ans, cnt);
               // cout<<ans<<" ";
            }
        }

        return dp[indx] = ans;
    }
    int minimumSubstringsInPartition(string s) {
        vector<int>dp(s.size(), -1);
        return solve(dp, s, 0);
    }
};