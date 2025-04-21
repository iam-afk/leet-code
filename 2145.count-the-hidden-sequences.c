// @leet start
#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

#define min(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a < _b ? _a : _b;                                                                             \
  })

int
numberOfArrays(int* differences, int differencesSize, int lower, int upper)
{
  int64_t mx = 0, mn = 0;
  int64_t d = 0;
  for (int i = 0; i < differencesSize; ++i) {
    d = d + differences[i];
    mx = max(mx, d);
    mn = min(mn, d);
  }
  return max(0, upper - lower - mx + mn + 1);
}
// @leet end