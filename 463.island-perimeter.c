// @leet start
int
islandPerimeter(int** grid, int grid_size, int* grid_col_size)
{
  int m = grid_size, n = grid_col_size[0], a = 0;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (grid[i][j] == 1)
        for (int k = 0; k < 4; ++k) {
          static int di[] = { -1, 0, 1, 0 }, dj[] = { 0, -1, 0, 1 };
          int r = i + di[k], c = j + dj[k];
          if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0)
            ++a;
        }
  return a;
}
// @leet end