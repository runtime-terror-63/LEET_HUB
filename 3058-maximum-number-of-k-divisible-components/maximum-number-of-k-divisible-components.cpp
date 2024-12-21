#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> adj;
    int ans = 0;

    void addEdge(int n, vector<vector<int>>& edges) {
        for (auto it : edges) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    long long dfs(int i, vector<int>& values, int k, vector<int>& vis) {
        vis[i] = 1;
        long long sum = values[i];
        for (auto it : adj[i]) {
            if (!vis[it]) {
                sum += dfs(it, values, k, vis);
                sum %= k;
            }
        }
        if (sum % k == 0) {
            ans++;
            return 0;
        }
        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        adj.resize(n);
        addEdge(n, edges);
        vector<int> vis(n, 0);
        dfs(0, values, k, vis);
        return ans;
    }
};
