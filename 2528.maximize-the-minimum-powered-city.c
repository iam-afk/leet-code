// @leet start
#define N (size_t)1e5
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

static bool
check(long long t, int k, int r, int n, long long const d[n])
{
  long long D[N + 1];
  memcpy(D, d, n * sizeof *d);
  long long s = 0;
  for (int i = 0; i < n; ++i) {
    s += D[i];
    if (s < t) {
      long long x = t - s;
      if (x > k)
        return false;
      s += x;
      k -= x;
      if (i + 2 * r + 1 <= n)
        D[i + 2 * r + 1] -= x;
    }
  }
  return true;
}

long long
maxPower(int* stations, int n, int r, int k)
{
  long long left = N, right = k + 1;
  for (int i = 0; i < n; ++i) {
    left = min(left, stations[i]);
    right += stations[i];
  }
  long long d[N + 1];
  memset(d, 0, (n + 1) * sizeof *d);
  for (int i = 0; i < n; ++i) {
    d[max(0, i - r)] += stations[i];
    d[min(n, i + r + 1)] -= stations[i];
  }
  while (left + 1 < right) {
    long long mid = left + (right - left) / 2;
    if (check(mid, k, r, n, d))
      left = mid;
    else
      right = mid;
  }
  return left;
}
// @leet end
//