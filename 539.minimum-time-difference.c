// @leet start
#define N (size_t)2e4

static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

#define min(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a < _b ? _a : _b;                                                        \
  })

int
findMinDifference(char** timePoints, int timePointsSize)
{
  static int ts[N];
  int n = 0;
  for (int i = 0; i < timePointsSize; ++i) {
    int h, m;
    sscanf(timePoints[i], "%d:%d", &h, &m);
    ts[n++] = h * 60 + m;
  }
  qsort(ts, n, sizeof(int), compare_ints);
  int ans = ts[0] + 24 * 60 - ts[n - 1];
  for (int i = 1; i < n; ++i)
    ans = min(ans, ts[i] - ts[i - 1]);
  return ans;
}
// @leet end