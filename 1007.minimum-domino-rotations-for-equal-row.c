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

int
minDominoRotations(int* tops, int topsSize, int* bottoms, int bottomsSize)
{
  int n = topsSize;
  int top[7] = {}, bottom[7] = {}, equal[7] = {};
  for (int i = 0; i < n; ++i) {
    ++top[tops[i]];
    ++bottom[bottoms[i]];
    if (tops[i] == bottoms[i])
      ++equal[tops[i]];
  }
  int ans = INT_MAX;
  for (int i = 1; i <= 6; ++i)
    if (top[i] + bottom[i] - equal[i] >= n)
      ans = min(ans, n - max(top[i], bottom[i]));
  return ans < INT_MAX ? ans : -1;
}
// @leet end