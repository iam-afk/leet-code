// @leet start
long long
maxSubarraySum(int* nums, int numsSize, int k)
{
  int64_t p[200000];
  for (int i = 0; i < k; ++i)
    p[i] = INT64_MAX / 2;
  p[k - 1] = 0;
  int64_t s = 0, ans = INT64_MIN;
  for (int i = 0; i < numsSize; ++i) {
    s += nums[i];
    if (ans < s - p[i % k])
      ans = s - p[i % k];
    if (s < p[i % k])
      p[i % k] = s;
  }
  return ans;
}
// @leet end