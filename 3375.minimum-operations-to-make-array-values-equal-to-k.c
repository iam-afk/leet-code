// @leet start
int
minOperations(int* nums, int numsSize, int k)
{
  bool f[101] = {};
  int ans = 0;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] < k)
      return -1;
    if (nums[i] > k && !f[nums[i]]) {
      f[nums[i]] = true;
      ++ans;
    }
  }
  return ans;
}
// @leet end