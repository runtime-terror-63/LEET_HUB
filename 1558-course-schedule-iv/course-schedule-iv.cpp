class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
    vector<vector<int>>adj(numCourses);
  for(auto& it : prerequisites){
    adj[it[0]].push_back(it[1]);
  }
 vector<unordered_set<int>>reachable(numCourses);
  for(auto course = 0; course<numCourses; course++){
    
    queue<int>q;
    q.push(course);

    while(!q.empty()){
      auto node = q.front();
      q.pop();

      for(auto it : adj[node]){
        if(reachable[course].find(it)==reachable[course].end()){
        reachable[course].insert(it);
        q.push(it);
        }
      }
    }
  }
  vector<bool>res;
  for(auto it : queries){
    int u = it[0], v = it[1];
    if(reachable[u].find(v) != reachable[u].end())
    res.push_back(1);
    else res.push_back(0);
  }
  return res;
    }
};