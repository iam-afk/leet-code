// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
productExceptSelf(int* nums, int nums_size, int* ret_size)
{
  int* ret = calloc(nums_size, sizeof *ret);

  ret[0] = 1;
  for (int i = 0; i < nums_size - 1; ++i)
    ret[i + 1] = ret[i] * nums[i];
  int prod = 1;
  for (int i = nums_size; i-- > 0;) {
    ret[i] = ret[i] * prod;
    prod *= nums[i];
  }

  *ret_size = nums_size;
  return ret;
}
// @leet end