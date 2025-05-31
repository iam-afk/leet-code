// @leet start
#define N 1000

#define swap(a, b)                                                            \
  {                                                                           \
    __typeof__(a) _t = (a);                                                   \
    (a) = (b);                                                                \
    (b) = _t;                                                                 \
  }

int
findTargetSumWays(int* nums, int numsSize, int target)
{
  int d[2][2 * N + 1] = {}, *p = d[0], *q = d[1];
  p[N] = 1;
  int sum = 0;
  for (int i = 0; i < numsSize; ++i) {
    memset(q, 0, (2 * N + 1) * sizeof *q);
    for (int x = -sum; x <= sum; ++x) {
      if (p[N + x] > 0) {
        q[N + x - nums[i]] += p[N + x];
        q[N + x + nums[i]] += p[N + x];
      }
    }
    swap(p, q);
    sum += nums[i];
  }
  return p[N + target];
}
// @leet end