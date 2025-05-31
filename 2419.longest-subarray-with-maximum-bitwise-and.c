// @leet start
#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

int
longestSubarray(int* nums, int numsSize)
{
  int mx = 0;
  for (int i = 0; i < numsSize; ++i)
    mx = max(mx, nums[i]);
  int ans = 0;
  for (int i = 0, d = 0; i < numsSize; ++i) {
    if (nums[i] != mx)
      d = 0;
    else
      ++d;
    ans = max(ans, d);
  }
  return ans;
}
// @leet end