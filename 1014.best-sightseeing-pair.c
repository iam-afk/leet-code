// @leet start

#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

int
maxScoreSightseeingPair(int* values, int valuesSize)
{
  int i = 0;
  int ans = 0;
  for (int j = 1; j < valuesSize; ++j) {
    ans = max(ans, values[j] + values[i] + i - j);
    if (values[i] - values[j] <= j - i)
      i = j;
  }
  return ans;
}
// @leet end