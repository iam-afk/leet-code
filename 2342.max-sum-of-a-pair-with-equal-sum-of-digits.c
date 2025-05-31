// @leet start
#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

int
maximumSum(int* nums, int numsSize)
{
  int sums[100] = {};
  int ans = -1;
  for (int i = 0; i < numsSize; ++i) {
    int s = 0;
    for (int n = nums[i]; n > 0; n /= 10)
      s += n % 10;
    if (sums[s] > 0)
      ans = max(ans, nums[i] + sums[s]);
    sums[s] = max(sums[s], nums[i]);
  }
  return ans;
}
// @leet end