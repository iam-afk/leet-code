// @leet start
long long
countSubarrays(int* nums, int numsSize, long long k)
{
  long long sum = 0, ans = 0;
  for (int i = -1, j = 0; j < numsSize; ++j) {
    sum += nums[j];
    while (i < j && sum * (j - i) >= k)
      sum -= nums[++i];
    ans += j - i;
  }
  return ans;
}
// @leet end