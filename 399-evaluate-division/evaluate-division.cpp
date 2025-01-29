class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> adj;
double bfs(string &start, string&end) {
  if (adj.find(start) == adj.end() || adj.find(end) == adj.end()) return -1.0;
    queue<pair<string, double>> q;
    q.push({start, 1.0});
    unordered_set<string> vis;
    vis.insert(start);

    while (!q.empty()) {
        string node = q.front().first;
        double product = q.front().second;
        q.pop();

        if (node == end) return product;

        for (auto& [nei, wei] : adj[node]) {
            if (vis.find(nei) == vis.end()) {
                q.push({nei, product * wei});
                vis.insert(nei);
            }
        }
    }
    return -1.0;
}



vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
    for (int i = 0; i < equations.size(); i++) {
        string u = equations[i][0], v = equations[i][1];
        double val = values[i];
        adj[u].push_back({v, val});
        adj[v].push_back({u, 1.0 / val});
    }

    vector<double> result;
    for (auto& it : queries) {
        result.push_back(bfs(it[0], it[1])); 
    }
    return result; 
}
};