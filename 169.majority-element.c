// @leet start
static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

int
majorityElement(int* nums, int nums_size)
{
  qsort(nums, nums_size, sizeof(int), compare_ints);
  return nums[nums_size / 2];
}
// @leet end