// @leet start
#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

int
lenLongestFibSubseq(int* arr, int arrSize)
{
  int ans = 0;
  for (int i = 0; i < arrSize; ++i)
    for (int j = i + 1; j < arrSize; ++j) {
      int x1 = arr[i], x2 = arr[j];
      int x3 = x1 + x2, *p, n = 2;
      while (bsearch(&x3, arr, arrSize, sizeof *arr, compare_ints)) {
        ++n;
        x1 = x2, x2 = x3, x3 = x1 + x2;
      }
      if (n > 2)
        ans = max(ans, n);
    };
  return ans;
}
// @leet end