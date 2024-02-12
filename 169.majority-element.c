// @leet start
int
majorityElement(int* nums, int nums_size)
{
  int m, d = 0;
  for (int i = 0; i < nums_size; ++i)
    if (d == 0)
      m = nums[i], d = 1;
    else if (nums[i] == m)
      ++d;
    else
      --d;
  return m;
}
// @leet end