

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
getSumAbsoluteDifferences(int* nums, int nums_size, int* return_size)
{
  int prefix[100000], suffix[100000];
  prefix[0] = nums[0];
  for (int i = 1; i < nums_size; ++i) {
    prefix[i] = prefix[i - 1] + nums[i];
  }
  suffix[nums_size - 1] = nums[nums_size - 1];
  for (int i = nums_size - 1; i-- > 0;) {
    suffix[i] = suffix[i + 1] + nums[i];
  }

  int* result = calloc(nums_size, sizeof *result);
  *return_size = nums_size;

  for (int i = 0; i < nums_size; ++i) {
    result[i] = nums[i] * (i + 1) - prefix[i] + suffix[i] - nums[i] * (nums_size - i);
  }

  return result;
}