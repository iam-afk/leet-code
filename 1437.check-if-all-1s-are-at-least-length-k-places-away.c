// @leet start
bool
kLengthApart(int* nums, int numsSize, int k)
{
  int p = -k - 1;
  for (int i = 0; i < numsSize; ++i) {
    if (nums[i] == 1) {
      if (i - p <= k)
        return false;
      p = i;
    }
  }
  return true;
}
// @leet end