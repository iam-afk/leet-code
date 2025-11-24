// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool*
prefixesDivBy5(int* nums, int numsSize, int* returnSize)
{
  bool* ret = calloc(numsSize, sizeof *ret);
  *returnSize = numsSize;
  int x = 0;
  for (int i = 0; i < numsSize; ++i) {
    x = (x << 1) + nums[i];
    x %= 5;
    ret[i] = x == 0;
  }
  return ret;
}
// @leet end