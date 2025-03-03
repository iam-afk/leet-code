// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
pivotArray(int* nums, int numsSize, int pivot, int* retSize)
{
  *retSize = numsSize;
  int* ret = calloc(*retSize, sizeof *ret);
  int l = 0, r = numsSize - 1;
  for (int i = 0, j = numsSize - 1; i < numsSize; ++i, --j) {
    if (nums[i] < pivot)
      ret[l++] = nums[i];
    if (nums[j] > pivot)
      ret[r--] = nums[j];
  }
  for (; l <= r; ++l)
    ret[l] = pivot;
  return ret;
}
// @leet end