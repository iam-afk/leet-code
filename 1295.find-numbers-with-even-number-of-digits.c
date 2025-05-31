// @leet start
int
findNumbers(int* nums, int numsSize)
{
  int ans = 0;
  for (int i = 0; i < numsSize; ++i)
    if (10 <= nums[i] && nums[i] < 100 || 1000 <= nums[i] && nums[i] < 10000 ||
        100000 <= nums[i])
      ++ans;
  return ans;
}
// @leet end