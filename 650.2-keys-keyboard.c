// @leet start

#define N (size_t)1e3

#define min(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a < _b ? _a : _b;                                                        \
  })

int
minSteps(int n)
{
  static int d[N + 1];
  for (int i = 2; i <= n; ++i)
    d[i] = i;
  d[1] = 0;
  for (int i = 1; i <= n; ++i) {
    int x = d[i] + 1;
    for (int j = 2 * i, k = 1; j <= n; j += i, ++k)
      d[j] = min(d[j], x + k);
  }
  return d[n];
}
// @leet end