// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
sortedSquares(int* nums, int nums_size, int* return_size)
{
  int* ret = calloc(nums_size, sizeof *ret);
  *return_size = nums_size;

  for (int i = 0, j = nums_size - 1, k = nums_size; i <= j;) {
    int x = abs(nums[i]) >= abs(nums[j]) ? i++ : j--;
    ret[--k] = nums[x] * nums[x];
  }

  return ret;
}
// @leet end