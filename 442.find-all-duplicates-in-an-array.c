// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
findDuplicates(int* nums, int nums_size, int* ret_size)
{
  for (int i = 0; i < nums_size;) {
    if (nums[i] == i + 1 || nums[nums[i] - 1] == nums[i])
      ++i;
    else {
      int t = nums[i];
      nums[i] = nums[nums[i] - 1];
      nums[t - 1] = t;
    }
  }
  int buf[100000], size = 0;
  for (int i = 0; i < nums_size; ++i)
    if (nums[i] != i + 1)
      buf[size++] = nums[i];
  *ret_size = size;
  int* ret = calloc(size, sizeof *ret);
  memcpy(ret, buf, size * sizeof *ret);
  return ret;
}
// @leet end