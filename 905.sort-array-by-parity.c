
static int
compare_parity(void const* a, void const* b)
{
  return *(int*)a & 1 - *(int*)b & 1;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
sortArrayByParity(int* nums, int nums_size, int* return_size)
{
  qsort(nums, nums_size, sizeof *nums, compare_parity);
  *return_size = nums_size;
  return nums;
}