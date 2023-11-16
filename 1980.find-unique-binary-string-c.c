static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

char*
findDifferentBinaryString(char** nums, int nums_size)
{
  int ints[16] = { 0 };
  for (int i = 0; i < nums_size; ++i) {
    for (int j = 0; j < nums_size; ++j)
      ints[i] = ints[i] * 2 + (nums[i][j] - '0');
  }
  qsort(ints, nums_size, sizeof(int), compare_ints);

  int unique = 0;
  while (unique < nums_size && ints[unique] == unique)
    ++unique;

  char* answer = malloc(nums_size + 1);
  for (int i = 0; i < nums_size; ++i) {
    answer[nums_size - i - 1] = (unique & 1) + '0';
    unique >>= 1;
  }
  answer[nums_size] = 0;
  return answer;
}