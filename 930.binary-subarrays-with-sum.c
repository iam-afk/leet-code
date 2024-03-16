// @leet start
int
numSubarraysWithSum(int* nums, int numsSize, int goal)
{
  int i = 0, sum = 0, ans = 0, z = 0;
  for (int j = 0; j < numsSize; ++j) {
    sum += nums[j];
    while (i < j && (nums[i] == 0 || sum > goal)) {
      if (nums[i] == 1)
        z = 0;
      else
        ++z;
      sum -= nums[i];
      ++i;
    }
    if (sum == goal)
      ans += 1 + z;
  }
  return ans;
}
// @leet end