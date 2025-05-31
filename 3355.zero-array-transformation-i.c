// @leet start

bool
isZeroArray(int* nums,
            int numsSize,
            int** queries,
            int queriesSize,
            int* queriesColSize)
{
  int d[100001];
  memset(d, 0, numsSize * sizeof *d);
  for (int i = 0; i < queriesSize; ++i) {
    int l = queries[i][0], r = queries[i][1];
    ++d[l], --d[r + 1];
  }

  int s = 0;
  for (int i = 0; i < numsSize; ++i) {
    s += d[i];
    if (s < nums[i])
      return false;
  }

  return true;
}
// @leet end