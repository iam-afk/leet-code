// @leet start

#define min(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a < _b ? _a : _b;                                                                             \
  })

#define N ((size_t)1e4)

int
numSquares(int n)
{
  int d[N + 1] = { 0, [1 ... N] = INT_MAX };
  for (int x = 0; x <= n; ++x)
    for (int j = 1; x + j * j <= n; ++j)
      d[x + j * j] = min(d[x + j * j], d[x] + 1);
  return d[n];
}
// @leet end