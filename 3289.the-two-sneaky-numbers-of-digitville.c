// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
getSneakyNumbers(int* nums, int numsSize, int* returnSize)
{
  *returnSize = 0;
  int* ret = calloc(2, sizeof *ret);

  bool f[100] = {};
  for (int i = 0; i < numsSize; ++i)
    if (f[nums[i]])
      ret[(*returnSize)++] = nums[i];
    else
      f[nums[i]] = true;

  return ret;
}
// @leet end