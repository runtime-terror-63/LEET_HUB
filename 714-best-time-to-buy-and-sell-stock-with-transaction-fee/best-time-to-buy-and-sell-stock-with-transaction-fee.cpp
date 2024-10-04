class Solution {
public:

    int func(vector<vector<int>>&dp, vector<int>&v, int ind, bool flag, int fee){
        int n = v.size();
        if(ind==n)return 0;
        if(dp[ind][flag]!=-1) return dp[ind][flag];

        int ans=0;

        if(flag){
            int take= -v[ind] + func(dp, v, ind+1, 0, fee);
            int ntake= func(dp, v, ind+1, 1, fee);
            ans=max(take, ntake);
        }else{
            int take= v[ind] + func(dp, v, ind+1, 1, fee) - fee;
            int ntake= func(dp, v, ind+1, 0, fee);
            ans=max(take, ntake);
        }
        return dp[ind][flag]=ans;
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return func(dp,prices,0,1,fee);
    }
};