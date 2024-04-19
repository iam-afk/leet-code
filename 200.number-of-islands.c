// @leet start
static void
dfs(char** grid, int m, int n, int i, int j)
{
  grid[i][j] = '0';
  if (i > 0 && grid[i - 1][j] == '1')
    dfs(grid, m, n, i - 1, j);
  if (j > 0 && grid[i][j - 1] == '1')
    dfs(grid, m, n, i, j - 1);
  if (i < m - 1 && grid[i + 1][j] == '1')
    dfs(grid, m, n, i + 1, j);
  if (j < n - 1 && grid[i][j + 1] == '1')
    dfs(grid, m, n, i, j + 1);
}

int
numIslands(char** grid, int grid_size, int* grid_col_size)
{
  int m = grid_size, n = grid_col_size[0];

  int a = 0;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < n; ++j)
      if (grid[i][j] == '1')
        ++a, dfs(grid, m, n, i, j);
  return a;
}
// @leet end