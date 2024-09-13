// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
xorQueries(int* arr,
           int arrSize,
           int** queries,
           int queriesSize,
           int* queriesColSize,
           int* returnSize)
{
  int* ret = calloc(queriesSize, sizeof *ret);
  *returnSize = queriesSize;

  static int p[(size_t)3e4 + 1];
  p[0] = 0;
  for (int i = 0; i < arrSize; ++i)
    p[i + 1] = p[i] ^ arr[i];
  for (int i = 0; i < queriesSize; ++i)
    ret[i] = p[queries[i][0]] ^ p[queries[i][1] + 1];

  return ret;
}
// @leet end