// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
rearrangeArray(int* nums, int nums_size, int* res_size)
{
  int* res = calloc(nums_size, sizeof *res);

  int p = 0, n = 1;
  for (int i = 0; i < nums_size; ++i)
    if (nums[i] < 0)
      res[n] = nums[i], n += 2;
    else
      res[p] = nums[i], p += 2;

  *res_size = nums_size;
  return res;
}
// @leet end