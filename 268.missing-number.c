// @leet start
int
missingNumber(int* nums, int nums_size)
{
  int x = 0;
  for (int i = 0; i <= nums_size; ++i)
    x ^= i;
  for (int i = 0; i < nums_size; ++i)
    x ^= nums[i];
  return x;
}
// @leet end