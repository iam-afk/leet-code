static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool*
checkArithmeticSubarrays(int* nums,
                         int nums_size,
                         int* l,
                         int l_size,
                         int* r,
                         int r_size,
                         int* return_size)
{
  *return_size = l_size;
  bool* answer = calloc(l_size, sizeof *answer);
  int array[500];
  for (int i = 0; i < l_size; ++i) {
    int n = r[i] - l[i] + 1;
    memcpy(array, nums + l[i], n * sizeof(int));
    qsort(array, n, sizeof(int), compare_ints);
    int d = array[1] - array[0];
    answer[i] = true;
    for (int j = 2; answer[i] && j < n; j++)
      answer[i] = array[j] - array[j - 1] == d;
  }
  return answer;
}