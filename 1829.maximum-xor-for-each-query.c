// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
getMaximumXor(int* nums, int numsSize, int maximumBit, int* retSize)
{
  int* ret = calloc(numsSize, sizeof *ret);
  *retSize = numsSize;

  int xor = 0, mx = (1 << maximumBit) - 1;
  for (int i = 0; i < numsSize; ++i) {
    xor ^= nums[i];
    ret[numsSize - i - 1] = mx ^ xor;
  }

  return ret;
}
// @leet end