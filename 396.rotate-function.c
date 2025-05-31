// @leet start
#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

int
maxRotateFunction(int* nums, int numsSize)
{
  int sum = 0, f = 0;
  for (int i = 0; i < numsSize; ++i) {
    sum += nums[i];
    f += i * nums[i];
  }
  int mx = f;
  for (int i = numsSize; i-- > 0;) {
    f += sum - nums[i] * numsSize;
    mx = max(mx, f);
  }
  return mx;
}
// @leet end