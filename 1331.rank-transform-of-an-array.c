// @leet start
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define N (size_t)1e5

static int
compare_ints(void const* a, void const* b, void* c)
{
  int i = *(int const*)a, j = *(int const*)b, *arr = (int*)c;
  return arr[i] - arr[j];
}

int*
arrayRankTransform(int* arr, int arrSize, int* returnSize)
{
  static int indices[N];
  for (int i = 0; i < arrSize; ++i)
    indices[i] = i;
  qsort_r(indices, arrSize, sizeof(int), compare_ints, arr);

  *returnSize = arrSize;
  int* ret = calloc(arrSize, sizeof *ret);
  for (int i = 0, rank = 0; i < arrSize; ++i) {
    if (i == 0 || arr[indices[i]] != arr[indices[i - 1]])
      ++rank;
    ret[indices[i]] = rank;
  }
  return ret;
}
// @leet end