// @leet start
#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

int
maxSumAfterPartitioning(int* arr, int arrSize, int k)
{
  int d[500] = { arr[0] }, p = 0;
  for (int i = 0; i < arrSize; ++i) {
    int mx = 0;
    for (int j = 0; j < k && i + j < arrSize; ++j) {
      mx = max(mx, arr[i + j]);
      d[i + j] = max(d[i + j], p + mx * (j + 1));
    }
    p = d[i];
  }
  return d[arrSize - 1];
}
// @leet end