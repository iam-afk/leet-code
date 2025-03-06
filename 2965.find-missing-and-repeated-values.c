// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
findMissingAndRepeatedValues(int** g, int n, int* gridColSize, int* retSize)
{
  int64_t perfect_sum = n * n * (n * n + 1) / 2;
  int64_t perfect_sum_2 = 1LL * n * n * (n * n + 1) * (2 * n * n + 1) / 6;

  int64_t sum = 0, sum_2 = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      sum += g[i][j];
      sum_2 += g[i][j] * g[i][j];
    }

  *retSize = 2;
  int* ret = calloc(2, sizeof *ret);
  ret[0] = (sum_2 - perfect_sum_2) / (sum - perfect_sum) + sum - perfect_sum;
  ret[0] /= 2;
  ret[1] = ret[0] - sum + perfect_sum;
  return ret;
}
// @leet end