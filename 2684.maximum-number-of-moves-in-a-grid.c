// @leet start

#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

int
maxMoves(int** grid, int gridSize, int* gridColSize)
{
  int d[2][1000];
  for (int i = 0; i < gridSize; ++i)
    d[0][i] = 0;
  int ans = 0;
  for (int j = 1; j < gridColSize[0]; ++j) {
    for (int i = 0; i < gridSize; ++i) {
      d[j & 1][i] = 0;
      if (i > 0 && grid[i - 1][j - 1] < grid[i][j] && (d[1 - (j & 1)][i - 1] > 0 || j == 1))
        d[j & 1][i] = max(d[j & 1][i], d[1 - (j & 1)][i - 1] + 1);
      if (grid[i][j - 1] < grid[i][j] && (d[1 - (j & 1)][i] > 0 || j == 1))
        d[j & 1][i] = max(d[j & 1][i], d[1 - (j & 1)][i] + 1);
      if (i + 1 < gridSize && grid[i + 1][j - 1] < grid[i][j] &&
          (d[1 - (j & 1)][i + 1] > 0 || j == 1))
        d[j & 1][i] = max(d[j & 1][i], d[1 - (j & 1)][i + 1] + 1);
      ans = max(ans, d[j & 1][i]);
    }
  }
  return ans;
}
// @leet end