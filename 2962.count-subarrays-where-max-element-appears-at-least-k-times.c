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
  int d[100001] = { 0 };
  for (int i = 0, n = 0; i < nums_size; ++i) {
    if (nums[i] == mx)
      ++n;
    d[i + 1] = n;
  }
  long long ans = 0;
  for (int i = 1, r = 1; i <= nums_size; ++i) {
    while (r <= nums_size && d[r] - d[i - 1] < k)
      ++r;
    ans += nums_size - r + 1;
  }
  return ans;
}
// @leet end