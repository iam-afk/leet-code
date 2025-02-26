// @leet start
#define min(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a < _b ? _a : _b;                                                                             \
  })

#define max(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a > _b ? _a : _b;                                                                             \
  })

int
maxAbsoluteSum(int* nums, int numsSize)
{
  int sum, mx_abs, mn, mx;
  mx_abs = abs(nums[0]);
  sum = mn = mx = nums[0];

  for (int i = 1; i < numsSize; ++i) {
    sum += nums[i];
    mx_abs = max(mx_abs, abs(sum));
    mx_abs = max(mx_abs, abs(sum - mx));
    mx_abs = max(mx_abs, abs(sum - mn));
    mn = min(mn, sum);
    mx = max(mx, sum);
  }

  return mx_abs;
}
// @leet end