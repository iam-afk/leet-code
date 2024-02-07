// @leet start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int**
findWinners(int** matches, int matches_size, int* matchesCol_size, int* res_len, int** res_col_len)
{
  int players[100001] = { [0 ... 100000] = -1 };
  for (int i = 0; i < matches_size; ++i) {
    for (int j = 0; j < 2; ++j)
      if (players[matches[i][j]] < 0)
        players[matches[i][j]] = 0;
    ++players[matches[i][1]];
  }

  *res_col_len = calloc(2, sizeof(int));
  for (int i = 1; i <= 100000; ++i) {
    if (players[i] == 0)
      ++(*res_col_len)[0];
    if (players[i] == 1)
      ++(*res_col_len)[1];
  }

  *res_len = 2;
  int** res = calloc(2, sizeof(int*));
  res[0] = calloc((*res_col_len)[0], sizeof(int));
  res[1] = calloc((*res_col_len)[1], sizeof(int));
  for (int i = 1, zero = 0, one = 0; i <= 100000; ++i) {
    if (players[i] == 0)
      res[0][zero++] = i;
    if (players[i] == 1)
      res[1][one++] = i;
  }

  return res;
}
// @leet end