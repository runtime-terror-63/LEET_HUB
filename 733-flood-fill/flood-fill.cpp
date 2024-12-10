class Solution {
public:
void dfs(int sr, int sc, vector<vector<int>> &image, int newColor, vector<vector<int>> &img_coppy, int initialColor, int delRow[], int delCol[])
{
  img_coppy[sr][sc] = newColor;
  int n = image.size();
  int m = image[0].size();
  for (int i = 0; i < 4; i++)
  {
    int nrow = sr + delRow[i];
    int ncol = sc + delCol[i];

    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && image[nrow][ncol] == initialColor && img_coppy[nrow][ncol] != newColor)
    {
      dfs(nrow, ncol, image, newColor, img_coppy, initialColor, delRow, delCol);
    }
  }
}
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
          int initialColor = image[sr][sc];

  vector<vector<int>> img_coppy = image;
  int delRow[] = {-1, 1, 0, 0};
  int delCol[] = {0, 0, -1, 1};

  dfs(sr, sc, image, color, img_coppy, initialColor, delRow, delCol);
  return img_coppy;
    }
};