// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
rearrangeArray(int* nums, int nums_size, int* res_size)
{
  int* res = calloc(nums_size, sizeof *res);

  int p = 0, n = 0;
  for (int i = 0; i < nums_size / 2; ++i) {
    while (p < nums_size && nums[p] < 0)
      ++p;
    res[i * 2] = nums[p++];
    while (n < nums_size && nums[n] > 0)
      ++n;
    res[i * 2 + 1] = nums[n++];
  }

  *res_size = nums_size;
  return res;
}
// @leet end