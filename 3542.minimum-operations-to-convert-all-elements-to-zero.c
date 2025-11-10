// @leet start
int
minOperations(int* nums, int numsSize)
{
  int s[100001], t = 0, ans = 0;
  s[t] = 0;
  for (int i = 0; i < numsSize; ++i) {
    while (s[t] > nums[i])
      --t;
    if (s[t] < nums[i])
      ++ans, s[++t] = nums[i];
  }
  return ans;
}
// @leet end