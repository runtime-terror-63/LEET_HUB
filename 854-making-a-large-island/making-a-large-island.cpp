class Solution {
public:
    int di[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int i, int j, vector<vector<int>>& grid, int islandId, unordered_map<int, int>& islandSize) {
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int>> q;
    q.push({i, j});
    grid[i][j] = islandId;
    int size = 1;

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int d = 0; d < 4; d++) {
            int nr = r + di[d];
            int nc = c + dy[d];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                grid[nr][nc] = islandId;
                q.push({nr, nc});
                size++;
            }
        }
    }
    islandSize[islandId] = size;
    return size;
}

int largestIsland(vector<vector<int>>& grid) {
    int islandId = 2;
    unordered_map<int, int> islandSize;
    int maxiSize = 0;
    int n = grid.size();
    int m = grid[0].size();

   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 1) {
                maxiSize = max(maxiSize, bfs(i, j, grid, islandId, islandSize));
                islandId++;
            }
        }
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                unordered_set<int> nei;
                int possi = 0;

                for (int d = 0; d < 4; d++) {
                    int nr = i + di[d];
                    int nc = j + dy[d];

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] > 1) {
                        nei.insert(grid[nr][nc]);
                    }
                }

                for (auto id : nei) {
                    possi += islandSize[id];
                }

                maxiSize = max(maxiSize, possi + 1);  //
            }
        }
    }

    return maxiSize;
}
};