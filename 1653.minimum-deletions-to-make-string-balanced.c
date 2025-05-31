// @leet start
#define min(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a < _b ? _a : _b;                                                        \
  })

int d[(size_t)1e5 + 1];

int
minimumDeletions(char* s)
{
  int n = d[n] = 0;
  for (int b = 0; s[n]; ++n) {
    if (s[n] == 'b')
      ++b;
    d[n + 1] = b;
  }
  int mn = d[n];
  for (int i = n, a = 0; i-- > 0;) {
    if (s[i] == 'a')
      ++a;
    mn = min(mn, a + d[i]);
  }
  return mn;
}
// @leet end