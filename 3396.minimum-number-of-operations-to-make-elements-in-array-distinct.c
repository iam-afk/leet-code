// @leet start
#define max(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a > _b ? _a : _b;                                                        \
  })

int
minimumOperations(int* nums, int numsSize)
{
  int d[101] = { [0 ... 100] = -1 };
  int mx = -1;
  for (int i = 0; i < numsSize; ++i) {
    if (d[nums[i]] >= 0)
      mx = max(mx, d[nums[i]]);
    d[nums[i]] = i;
  }
  printf("%d\n", mx);
  return mx < 0 ? 0 : mx / 3 + 1;
}
// @leet end