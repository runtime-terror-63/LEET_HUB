class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);
        vector<int>indegree(numCourses, 0);

        queue<int>q;
        for(const auto &pair : prerequisites){
            int course = pair[0];
            int prerequist = pair[1];
            adj[prerequist].push_back(course);
            indegree[course]++;
        }

        //initialize queue all nodes that have indegree 0
        for(int i = 0;  i< numCourses; i++){
            if(indegree[i]==0)
            q.push(i);
        }

        //bfs do
        int cmnCnt = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            cmnCnt++;

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }

        return numCourses == cmnCnt;
    }
};