// @leet start
#define min(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a < _b ? _a : _b;                                                        \
  })

#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

#define N ((size_t)70)

int
cherryPickup(int** grid, int grid_size, int* grid_colsize)
{
  int n = grid_size, m = grid_colsize[0];
  int d[2][N][N] = {};
  d[0][0][m - 1] = grid[0][0] + grid[0][m - 1];
  for (int k = 1, p = 1; k < grid_size; ++k, p ^= 1)
    for (int i = 0; i < m; ++i)
      for (int j = 0; j < m; ++j)
        if (i > k || j < m - 1 - k)
          d[p][i][j] = 0;
        else {
          int pmx = 0;
          for (int pi = max(i - 1, 0); pi < min(i + 2, m); ++pi)
            for (int pj = max(j - 1, 0); pj < min(j + 2, m); ++pj)
              pmx = max(pmx, d[p ^ 1][pi][pj]);
          d[p][i][j] = pmx + grid[k][i];
          if (i != j)
            d[p][i][j] += grid[k][j];
        }
  int mx = 0;
  for (int i = 0; i < m; ++i)
    for (int j = 0; j < m; ++j)
      mx = max(mx, d[grid_size - 1 & 1][i][j]);
  return mx;
}
// @leet end