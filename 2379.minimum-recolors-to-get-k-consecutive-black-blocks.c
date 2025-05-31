// @leet start
#define min(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a < _b ? _a : _b;                                                        \
  })

int
minimumRecolors(char* blocks, int k)
{
  int d[101];
  d[0] = 0;
  int ans = 10000;
  for (int i = 0; blocks[i]; ++i) {
    d[i + 1] = d[i] + (blocks[i] == 'W');
    if (i + 1 >= k)
      ans = min(ans, d[i + 1] - d[i - k + 1]);
  }

  return ans;
}
// @leet end