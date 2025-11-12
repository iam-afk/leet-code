// @leet start
int
gcd(int a, int b)
{
  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

#define min(a, b)                                                             \
  ({                                                                          \
    __typeof__(a) _a = (a);                                                   \
    __typeof__(b) _b = (b);                                                   \
    _a < _b ? _a : _b;                                                        \
  })

int
minOperations(int* nums, int numsSize)
{
  int g = 0, ones = 0;
  for (int i = 0; i < numsSize; ++i) {
    g = gcd(g, nums[i]);
    if (nums[i] == 1)
      ++ones;
  }
  if (ones > 0)
    return numsSize - ones;
  if (g > 1)
    return -1;
  int mn = numsSize;
  for (int i = 0; i < numsSize; ++i) {
    int g = nums[i];
    for (int j = i + 1; j < numsSize; ++j) {
      g = gcd(g, nums[j]);
      if (g == 1)
        mn = min(mn, j - i + 1);
    }
  }
  return numsSize + mn - 2;
}
// @leet end