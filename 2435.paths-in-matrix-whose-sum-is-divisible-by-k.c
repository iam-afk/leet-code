// @leet start
#define M (int)(1e9 + 7)

int
numberOfPaths(int** grid, int gridSize, int* gridColSize, int k)
{
  int m = gridSize, n = gridColSize[0];
  int d[2][50000][50];
  for (int r = 0; r < k; ++r)
    d[0][0][r] = 0;
  d[0][0][grid[0][0] % k] = 1;
  for (int j = 1; j < n; ++j)
    for (int r = 0; r < k; ++r)
      d[0][j][(r + grid[0][j]) % k] = d[0][j - 1][r];
  for (int i = 1; i < m; ++i) {
    for (int r = 0; r < k; ++r)
      d[i & 1][0][(r + grid[i][0]) % k] = d[1 - i & 1][0][r];
    for (int j = 1; j < n; ++j)
      for (int r = 0; r < k; ++r) {
        d[i & 1][j][(r + grid[i][j]) % k] = d[1 - i & 1][j][r];
        d[i & 1][j][(r + grid[i][j]) % k] += d[i & 1][j - 1][r];
        d[i & 1][j][(r + grid[i][j]) % k] %= M;
      }
  }
  return d[(m - 1) & 1][n - 1][0];
}
// @leet end