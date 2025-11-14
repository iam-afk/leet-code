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
    d[r1][c1] += 1;
    d[r1][c2 + 1] -= 1;
    d[r2 + 1][c1] -= 1;
    d[r2 + 1][c2 + 1] += 1;
  }

  int** ret = calloc(n, sizeof *ret);
  *returnSize = n;
  *returnColumnSizes = calloc(n, sizeof **returnColumnSizes);
  for (int i = 0; i < n; ++i) {
    ret[i] = calloc(n, sizeof *ret[i]);
    (*returnColumnSizes)[i] = n;
  }
  for (int r = 0; r < n; ++r)
    for (int c = 0; c < n; ++c)
      ret[r][c] = d[r][c] + (r == 0 ? 0 : ret[r - 1][c]) +
                  (c == 0 ? 0 : ret[r][c - 1]) -
                  (r == 0 || c == 0 ? 0 : ret[r - 1][c - 1]);
  return ret;
}
// @leet end