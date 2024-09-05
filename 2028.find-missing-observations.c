// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define min(a, b)                                                                                  \
  ({                                                                                               \
    __typeof__(a) _a = (a);                                                                        \
    __typeof__(b) _b = (b);                                                                        \
    _a < _b ? _a : _b;                                                                             \
  })

int*
missingRolls(int* rolls, int rollsSize, int mean, int n, int* returnSize)
{
  // 1 + 5 + 6 = 12, 3 * (4 + 3) = 3 * 7 = 21
  // 21 - 12 = 9, 6, 1, 1, 1
  int m = rollsSize;
  int sum = mean * (m + n);
  for (int i = 0; i < m; ++i)
    sum -= rolls[i];
  printf("%d\n", sum);
  if (sum < n || sum > 6 * n) {
    *returnSize = 0;
    return 0;
  }
  static int d[(size_t)1e5];

  for (int i = 0; i < n; ++i)
    sum -= d[i] = min(6, sum - (n - i - 1));

  *returnSize = n;
  int* ret = calloc(n, sizeof *ret);
  memcpy(ret, d, n * sizeof *ret);
  return ret;
}
// @leet end