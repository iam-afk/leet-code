// @leet start
int
firstMissingPositive(int* nums, int nums_size)
{
  int j = 0;
  for (int i = 0; i < nums_size;)
    if (1 <= nums[i] && nums[i] <= nums_size && nums[i] != nums[nums[i] - 1]) {
      int t = nums[i];
      nums[i] = nums[nums[i] - 1];
      nums[t - 1] = t;
    } else
      ++i;
  for (int i = 0; i < nums_size; ++i)
    if (nums[i] != i + 1)
      return i + 1;
  return nums_size + 1;
}
// @leet end