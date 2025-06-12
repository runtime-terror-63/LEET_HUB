class Solution {
public:
void dfs(int ind, vector<vector<int>>&rooms, vector<bool>&visit){
  visit[ind] = true;
  for(auto it : rooms[ind]){
    if(!visit[it]) dfs(it, rooms, visit);
  }
}
bool canVisitAllRooms(vector<vector<int>>& rooms) {
  vector<bool>visit(rooms.size(), false);
  visit[0] = true;
  dfs(0, rooms, visit); 
  
  for(auto it : visit) {
    if(!it) return false;
  }
  return true;
}
};