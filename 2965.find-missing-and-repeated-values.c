// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
findMissingAndRepeatedValues(int** grid, int gridSize, int* gridColSize, int* retSize)
{
  int* ret = calloc(2, sizeof *ret);
  *retSize = 2;

  bool f[50 * 50] = {};

  for (int i = 0; i < gridSize; ++i)
    for (int j = 0; j < gridSize; ++j) {
      int n = grid[i][j];
      if (f[n - 1])
        ret[0] = n;
      else
        f[n - 1] = true;
    }
  for (int i = 1; i <= gridSize * gridSize; ++i)
    if (!f[i - 1])
      ret[1] = i;

  return ret;
}
// @leet end