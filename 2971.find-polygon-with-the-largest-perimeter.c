// @leet start
static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

long long
largestPerimeter(int* nums, int nums_size)
{
  qsort(nums, nums_size, sizeof(int), compare_ints);
  int64_t sum = 0, p = -1;
  for (int i = 0; i < nums_size; ++i) {
    if (nums[i] < sum)
      p = nums[i] + sum;
    sum += nums[i];
  }
  return p;
}
// @leet end