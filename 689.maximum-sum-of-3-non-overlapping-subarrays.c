// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

int*
maxSumOfThreeSubarrays(int* nums, int numsSize, int k, int* retSize)
{
  int p[20002] = { 0 };
  for (int i = 0; i < numsSize; ++i)
    p[i + 1] = p[i] + nums[i];
  int d[3][20002] = {};
  for (int i = k; i <= numsSize; ++i)
    d[0][i] = max(d[0][i - 1], p[i] - p[i - k]);
  for (int t = 1; t < 3; ++t)
    for (int i = 0; i <= numsSize - k; ++i)
      if (d[t - 1][i] > 0)
        d[t][i + k] = max(d[t][i + k - 1], d[t - 1][i] + p[i + k] - p[i]);

  *retSize = 3;
  int* ret = calloc(*retSize, sizeof *ret);
  int i = numsSize;
  for (int t = 3; t-- > 0;) {
    while (d[t][i] == d[t][i - 1])
      --i;
    ret[t] = i - k;
    i = i - k;
  }
  return ret;
}
// @leet end