// @leet start
int
countSubarrays(int* nums, int numsSize)
{
  int ans = 0;
  for (int i = 1; i < numsSize - 1; ++i)
    ans += 2 * (nums[i - 1] + nums[i + 1]) == nums[i];
  return ans;
}
// @leet end