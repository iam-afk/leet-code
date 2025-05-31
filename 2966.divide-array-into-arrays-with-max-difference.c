// @leet start
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */

static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

int**
divideArray(int* nums,
            int nums_size,
            int k,
            int* return_size,
            int** return_column_size)
{
  qsort(nums, nums_size, sizeof(int), compare_ints);

  int m = nums_size / 3;
  for (int i = 0; i < m; ++i)
    if (nums[i * 3 + 2] - nums[i * 3] > k) {
      *return_size = 0;
      *return_column_size = 0;
      return 0;
    }

  int** ret = calloc(m, sizeof *ret);
  *return_size = nums_size / 3;
  *return_column_size = calloc(*return_size, sizeof **return_column_size);
  for (int i = 0; i < *return_size; ++i) {
    ret[i] = &nums[i * 3];
    (*return_column_size)[i] = 3;
  }
  return ret;
}
// @leet end