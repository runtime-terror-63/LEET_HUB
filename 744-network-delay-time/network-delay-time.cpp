class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1); 
        for (int i = 0; i < times.size(); i++) {
            int u = times[i][0], v = times[i][1], w = times[i][2];
            adj[u].push_back({v, w});
        }

        vector<int> vis(n + 1, 1e9); 
        vis[k] = 0; 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k}); // {distance, node}

        while (!pq.empty()) {
            int wei = pq.top().first; 
            int node = pq.top().second; 
            pq.pop();

            for (auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                if (vis[adjNode] > wei + wt) {
                    vis[adjNode] = wei + wt;
                    pq.push({vis[adjNode], adjNode});
                }
            }
        }

        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (vis[i] == 1e9) return -1; 
            ans = max(ans, vis[i]);
        }
        return ans;
    }
};
