// @leet start
int
firstMissingPositive(int* nums, int nums_size)
{
  int j = 0;
  for (int i = 0; i < nums_size;) {
    if (1 <= nums[i] && nums[i] <= nums_size && nums[i] - 1 <= i) {
      int t = nums[i];
      nums[i] = nums[nums[i] - 1];
      nums[t - 1] = t;
      if (i == j || t - 1 == j)
        while (j <= i && nums[j] == j + 1)
          ++j;
      if (t >= i + 1 || t == nums[i])
        ++i;
    } else
      ++i;
  }
  return j + 1;
}
// @leet end