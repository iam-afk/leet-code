// @leet start
#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

int
minNumberOperations(int* target, int targetSize)
{
  int ans = target[0];
  for (int i = 1; i < targetSize; ++i)
    ans += max(0, target[i] - target[i - 1]);
  return ans;
}
// @leet end