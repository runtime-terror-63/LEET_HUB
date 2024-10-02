class Solution {
public:
   bool bfs(int s, vector<int>&color, vector<vector<int>>&graph){
    queue<int>q;
    q.push(s);
    color[s] = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto it : graph[node]){
            if(color[it] == -1){
                color[it] = !color[node];
                q.push(it);
            }else if(color[node]==color[it]) return false;
        }
    }
    return true;
   }

bool dfs(int s, int i, vector<int>& color, vector<vector<int>>& graph) {
    color[s] = i;
    for (auto it : graph[s]) {
        if (color[it] == -1) {
            if (dfs(it, !i, color, graph) == false) return false;
        } 
        else if (color[it] == color[s]) {
            return false;  
        }
    }
    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n, -1);
        for(int i = 0; i<n; i++){
            if(color[i]==-1){
                if(dfs(i, 0, color, graph)==false) return false;
            }
        }
        return true;
    }
};