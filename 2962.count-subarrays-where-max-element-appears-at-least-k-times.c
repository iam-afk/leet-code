// @leet start
#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

long long
countSubarrays(int* nums, int nums_size, int k)
{
  int mx = 0;
  for (int i = 0; i < nums_size; ++i)
    mx = max(mx, nums[i]);
  long long ans = 0;
  for (int i = 0, j = 0; j < nums_size; ++j) {
    if (nums[j] == mx)
      --k;
    while (k == 0) {
      if (nums[i] == mx)
        ++k;
      ++i;
    }
    ans += i;
  }
  return ans;
}
// @leet end