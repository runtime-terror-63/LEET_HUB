class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>R(n);
        vector<int>outdegree(n), safe(n), ans;
        queue<int>q;
        for(int i=0; i<n; i++){
            for(auto v : graph[i]) R[v].push_back(i);

            outdegree[i] = graph[i].size();
            if(outdegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe[node] = 1;
            for(auto v : R[node]) 
              if(--outdegree[v] == 0) q.push(v);
        }

        for(int i=0; i<n; i++) 
          if(safe[i]) ans.push_back(i);
          return ans;
    }
};