// @leet start
#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

int
findMaxForm(char** strs, int strsSize, int m, int n)
{
  int d[101][101] = {};
  for (int i = 0; i < strsSize; ++i) {
    int c0 = 0, c1 = 0;
    for (int j = 0; strs[i][j]; ++j)
      c0 += strs[i][j] == '0', c1 += strs[i][j] == '1';
    for (int r = m; r >= c0; --r)
      for (int c = n; c >= c1; --c)
        d[r][c] = max(d[r][c], d[r - c0][c - c1] + 1);
  }
  return d[m][n];
}
// @leet end