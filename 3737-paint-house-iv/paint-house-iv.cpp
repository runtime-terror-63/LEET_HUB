class Solution {
public:
    #define ll long long 

long long fn(vector<vector<int>>& cost, int day, int l, int r, vector<vector<vector<ll>>>& dp) {
    int n = cost.size();
    if (dp[day][l][r] != -1) 
        return dp[day][l][r];
    if (day >= n / 2) 
        return 0;

    vector<int> left, right;
    for (int i = 0; i < 3; i++) {
        if (l != i) 
            left.push_back(i);
        if (r != i) 
            right.push_back(i);
    }

    ll ans = 1e14;
    for (auto it1 : left) {
        for (auto it2 : right) {
            if (it1 == it2) 
                continue;
            ll cl = cost[day][it1], cr = cost[n - day - 1][it2];
            ans = min(ans, cl + cr + fn(cost, day + 1, it1, it2, dp));
        }
    }
    return dp[day][l][r] = ans;
}

long long minCost(int n, vector<vector<int>>& cost) {
    vector<vector<vector<ll>>> dp(n / 2 + 1, vector<vector<ll>>(4, vector<ll>(4, -1)));
    return fn(cost, 0, 3, 3, dp);
}
};