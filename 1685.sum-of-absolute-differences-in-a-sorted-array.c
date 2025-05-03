

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
getSumAbsoluteDifferences(int* nums, int nums_size, int* return_size)
{
  int sum = 0;
  for (int i = 0; i < nums_size; ++i)
    sum += nums[i];

  int* result = calloc(nums_size, sizeof *result);
  *return_size = nums_size;

  int prefix_sum = 0;
  for (int i = 0; i < nums_size; ++i) {
    prefix_sum += nums[i];
    result[i] = nums[i] * (2 * i + 2 - nums_size) - 2 * prefix_sum + sum;
  }

  return result;
}