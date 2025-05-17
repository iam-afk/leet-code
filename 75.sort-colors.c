// @leet start
void
sortColors(int* nums, int numsSize)
{
  int c[3] = {};
  for (int i = 0; i < numsSize; ++i)
    ++c[nums[i]];
  for (int i = 0, k = 0; k < 3; ++k)
    for (int j = 0; j < c[k]; ++j, ++i)
      nums[i] = k;
}
// @leet end