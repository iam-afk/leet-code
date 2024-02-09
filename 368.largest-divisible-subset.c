// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define N ((size_t)1e3)

static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

int*
largestDivisibleSubset(int* nums, int nums_size, int* res_size)
{
  qsort(nums, nums_size, sizeof(int), compare_ints);
  int d[N] = { [0 ... N - 1] = 1 };
  int b = 1, k = 0;
  for (int i = 1; i < nums_size; ++i)
    for (int j = 0; j < i; ++j)
      if (nums[i] % nums[j] == 0 && d[i] < d[j] + 1) {
        d[i] = d[j] + 1;
        if (d[i] > b)
          b = d[i], k = i;
      }

  *res_size = b;
  int* res = calloc(b, sizeof *res);

  res[--b] = nums[k];
  for (int i = k; b > 0; --i) {
    if (d[i] + 1 == d[k] && nums[k] % nums[i] == 0) {
      res[--b] = nums[i];
      k = i;
    }
  }

  return res;
}
// @leet end