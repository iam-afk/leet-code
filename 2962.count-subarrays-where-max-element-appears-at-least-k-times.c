// @leet start
long long
countSubarrays(int* nums, int numsSize, int k)
{
  int64_t ans = 0;
  int mx = nums[0];
  for (int i = 1; i < numsSize; ++i)
    if (mx < nums[i])
      mx = nums[i];
  int mxn = 0;
  for (int l = 0, r = 0; r < numsSize; ++r) {
    if (nums[r] == mx)
      ++mxn;
    if (mxn >= k) {
      for (; l <= r && mxn >= k; ++l) {
        ans += numsSize - r;
        if (nums[l] == mx)
          --mxn;
      }
    }
  }
  return ans;
}
// @leet end