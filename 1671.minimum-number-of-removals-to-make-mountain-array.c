// @leet start
#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

int
minimumMountainRemovals(int* nums, int numsSize)
{
  int d1[1000];
  for (int i = 0; i < numsSize; ++i) {
    d1[i] = 1;
    for (int j = 0; j < i; ++j)
      if (nums[j] < nums[i])
        d1[i] = max(d1[i], d1[j] + 1);
  }
  int d2[1000];
  for (int i = numsSize; i-- > 0;) {
    d2[i] = 1;
    for (int j = i + 1; j < numsSize; ++j)
      if (nums[j] < nums[i])
        d2[i] = max(d2[i], d2[j] + 1);
  }
  int mx = 0;
  for (int i = 1; i < numsSize - 1; ++i)
    if (d1[i] > 1 && d2[i] > 1)
      mx = max(mx, d1[i] + d2[i] - 1);
  return numsSize - mx;
}
// @leet end