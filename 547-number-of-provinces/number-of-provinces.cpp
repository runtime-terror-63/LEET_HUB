class Solution {
public:

    void dfs(int ind, vector<int>adj[], vector<int>&vis){
        vis[ind] = 1;
        for(auto it : adj[ind]){
            if(!vis[it]) dfs(it, adj, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int v = isConnected.size();
        vector<int>visited(v, 0);
        vector<int>ans[v];
        for(int i = 0; i<v; i++){
            for(int j = 0; j<v; j++){
                if(isConnected[i][j]==1 && i!=j){
                    ans[i].push_back(j);
                    ans[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i<v; i++){
            if(!visited[i]){
                dfs(i, ans, visited);
                cnt++;
            }
        }
        return cnt;
    }
};