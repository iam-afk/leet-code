// @leet start
int
minimumOperations(int* nums, int numsSize)
{
  int ans = 0;
  for (int i = 0; i < numsSize; ++i)
    ans += nums[i] % 3 != 0;
  return ans;
}
// @leet end