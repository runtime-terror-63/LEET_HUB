class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : times) {
            int u = edge[0], v = edge[1], wt = edge[2];
            adj[u].push_back({v, wt});
        }

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

  
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            for (auto& [nei, wt] : adj[node]) {
                if (d + wt < dist[nei]) {
                    dist[nei] = d + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == 1e9) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
