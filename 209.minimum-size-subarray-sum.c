// @leet start
int
minSubArrayLen(int target, int* nums, int numsSize)
{
  int l = 0, r = 0, sum = 0;
  int ans = INT_MAX;
  while (r < numsSize) {
    sum += nums[r], ++r;
    while (r < numsSize && sum < target)
      sum += nums[r], ++r;
    while (l < r && sum - nums[l] >= target)
      sum -= nums[l], ++l;
    if (sum >= target && r - l < ans)
      ans = r - l;
  }
  return ans < INT_MAX ? ans : 0;
}
// @leet end