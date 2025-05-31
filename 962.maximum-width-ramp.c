// @leet start
#define N (size_t)5e5

#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

int
maxWidthRamp(int* nums, int numsSize)
{
  static int idx[N];

  int j = 0;
  idx[j] = 0;

  for (int i = 1; i < numsSize; ++i)
    if (nums[i] < nums[idx[j]])
      idx[++j] = i;

  int ans = 0;
  for (int i = numsSize; i-- > 0;)
    while (j >= 0 && nums[i] >= nums[idx[j]])
      ans = max(ans, i - idx[j--]);

  return ans;
}
// @leet end