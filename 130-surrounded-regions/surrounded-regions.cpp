class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& board, int n, int m) {
        vis[row][col] = 1;
        int delrow[] = {-1, 1, 0, 0};
        int delcol[] = {0, 0, 1, -1};
        
        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            // Check if the new position is valid and contains 'O'
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && board[nrow][ncol] == 'O') 
                dfs(nrow, ncol, vis, board, n, m);
        }
    }

    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Check the first and last columns
        for (int j = 0; j < n; j++) {
            if (!vis[j][0] && board[j][0] == 'O')
                dfs(j, 0, vis, board, n, m);
            if (!vis[j][m-1] && board[j][m-1] == 'O')
                dfs(j, m-1, vis, board, n, m);
        }

        // Check the first and last rows
        for (int i = 0; i < m; i++) {
            if (!vis[0][i] && board[0][i] == 'O')
                dfs(0, i, vis, board, n, m);
            if (!vis[n-1][i] && board[n-1][i] == 'O')
                dfs(n-1, i, vis, board, n, m);
        }

        // Flip all unvisited 'O' cells to 'X'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }
};
