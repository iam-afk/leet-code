// @leet start
#define min(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a < _b ? _a : _b;                                                        \
  })
#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

long long
maximumValueSum(int* nums,
                int numsSize,
                int k,
                int** edges,
                int edgesSize,
                int* edgesColSize)
{
  int64_t sum = 0, pmn = INT_MAX, nmx = INT_MIN, n = 0;
  for (int i = 0; i < numsSize; ++i) {
    sum += nums[i];
    int d = (nums[i] ^ k) - nums[i];
    if (d > 0) {
      sum += d;
      pmn = min(pmn, d);
      ++n;
    } else {
      nmx = max(nmx, d);
    }
  }
  if (n & 1)
    return max(sum + nmx, sum - pmn);
  return sum;
}
// @leet end