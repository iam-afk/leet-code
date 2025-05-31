// @leet start
#define min(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a < _b ? _a : _b;                                                        \
  })

long long
countSubarrays(int* nums, int nums_size, int min_k, int max_k)
{
  long long a = 0;
  int start = 0;
  while (start < nums_size) {
    int end = start;
    while (end < nums_size && min_k <= nums[end] && nums[end] <= max_k)
      ++end;
    int last_min_k = -1, last_max_k = -1;
    for (int i = start; i < end; ++i) {
      if (nums[i] == min_k)
        last_min_k = i;
      if (nums[i] == max_k)
        last_max_k = i;
      if (last_min_k >= 0 && last_max_k >= 0)
        a += min(last_min_k, last_max_k) - start + 1;
    }
    start = end + 1;
  }
  return a;
}
// @leet end