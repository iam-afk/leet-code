// @leet start
static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

int
countPairs(int* nums, int nums_size, int target)
{
  qsort(nums, nums_size, sizeof(int), compare_ints);
  int a = 0;
  for (int i = 0, j = nums_size - 1; i < j; ++i) {
    while (i < j && nums[i] + nums[j] >= target)
      --j;
    a += j - i;
  }
  return a;
}
// @leet end