class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
          int n = isWater.size();
  int m = isWater[0].size();

  int dx[] = {-1,0,+1,0};
  int dy[] = {0,+1,0,-1};

  vector<vector<int>>newMat(n, vector<int>(m, -1));
  queue<pair<int, int>>q;

  for(int i=0; i<n; i++){
    for(int j=0; j<m; j++){
      if(isWater[i][j]==1){
        newMat[i][j] = 0;
        q.push({i, j});
      }
    }
  }

  while(!q.empty()){
    auto it = q.front();
    int xi = it.first;
    int yj = it.second;
    q.pop();

    for(int i=0; i<4; i++){
      int x = xi + dx[i];
      int y = yj + dy[i];

      if(x>=0 && x<n && y>=0 && y<m && newMat[x][y]==-1){
        newMat[x][y] = newMat[xi][yj]+1;
        q.push({x, y});
      }
    }
  }
  return newMat;
    }
};