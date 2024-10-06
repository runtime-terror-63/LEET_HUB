class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> visited(n, 0);
        int sum = 0;
        int count = 0;
        
        pq.push({0, 0}); 
        
        while (!pq.empty() && count < n) {
            auto [weight, node] = pq.top();
            pq.pop(); 
            if (visited[node]) continue;
            visited[node] = 1;
            sum += weight;
            count++;
            for (int next = 0; next < n; next++) {
                if (!visited[next]) {
                    int cost = abs(points[node][0] - points[next][0]) + abs(points[node][1] - points[next][1]);
                    pq.push({cost, next});
                }
            }
        }
        return sum;
    }
};