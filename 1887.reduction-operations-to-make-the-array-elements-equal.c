static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

int
reductionOperations(int* nums, int nums_size)
{
  qsort(nums, nums_size, sizeof(int), compare_ints);
  int answer = 0;
  for (int i = 1; i < nums_size; ++i)
    if (nums[i - 1] < nums[i])
      answer += nums_size - i;
  return answer;
}