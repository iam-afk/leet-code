// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
buildArray(int* nums, int numsSize, int* returnSize)
{
  *returnSize = numsSize;
  for (int i = 0; i < numsSize; ++i)
    nums[i] += nums[nums[i]] % 1000 * 1000;
  for (int i = 0; i < numsSize; ++i)
    nums[i] /= 1000;
  return nums;
}
// @leet end