// @leet start
#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

int
maxSumDivThree(int* nums, int numsSize)
{
  int d[] = { 0, INT_MIN, INT_MIN };
  for (int i = 0; i < numsSize; ++i) {
    int t[3];
    memcpy(t, d, sizeof t);
    for (int j = 0; j < 3; ++j)
      t[(j + nums[i]) % 3] = max(t[(j + nums[i]) % 3], d[j] + nums[i]);
    memcpy(d, t, sizeof d);
  }
  return d[0];
}
// @leet end