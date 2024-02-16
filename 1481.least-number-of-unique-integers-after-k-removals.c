static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

#define N ((size_t)1e5)

int
findLeastNumOfUniqueInts(int* arr, int arr_size, int k)
{
  qsort(arr, arr_size, sizeof(int), compare_ints);
  int c[N] = { 1 }, j = 0;
  for (int i = 1; i < arr_size; ++i)
    if (arr[i - 1] == arr[i])
      ++c[j];
    else
      c[++j] = 1;
  qsort(c, j + 1, sizeof(int), compare_ints);
  int i = 0;
  while (k > 0) {
    if (k < c[i])
      break;
    k -= c[i++];
  }
  return j + 1 - i;
}