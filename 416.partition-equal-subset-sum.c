// @leet start
#define min(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a < _b ? _a : _b;                                                        \
  })

bool
canPartition(int* nums, int numsSize)
{
  int sum = 0;
  for (int i = 0; i < numsSize; ++i)
    sum += nums[i];
  if (sum % 2 != 0)
    return false;
  bool d[2][20001] = {};
  d[0][0] = d[1][0] = true;
  int mxs = 0, p = 0;
  for (int i = 0; i < numsSize; ++i, p = 1 - p) {
    mxs += nums[i];
    for (int j = 1; j <= min(sum / 2, mxs + nums[i]); ++j)
      d[1 - p][j] = d[p][j] || j >= nums[i] && d[p][j - nums[i]];
  }
  return d[p][sum / 2];
}
// @leet end