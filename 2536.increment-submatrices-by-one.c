// @leet start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
int**
rangeAddQueries(int n,
                int** queries,
                int queriesSize,
                int* queriesColSize,
                int* returnSize,
                int** returnColumnSizes)
{
  int d[501][501] = {};
  for (int i = 0; i < queriesSize; ++i) {
    int r1 = queries[i][0], c1 = queries[i][1], r2 = queries[i][2],
        c2 = queries[i][3];
    for (int r = r1; r <= r2; ++r)
      d[r][c1] += 1, d[r][c2 + 1] -= 1;
  }

  int** ret = calloc(n, sizeof *ret);
  *returnSize = n;
  *returnColumnSizes = calloc(n, sizeof **returnColumnSizes);
  for (int i = 0; i < n; ++i) {
    ret[i] = calloc(n, sizeof *ret[i]);
    (*returnColumnSizes)[i] = n;
  }
  for (int r = 0; r < n; ++r) {
    int v = 0;
    for (int c = 0; c < n; ++c)
      ret[r][c] = v += d[r][c];
  }
  return ret;
}
// @leet end