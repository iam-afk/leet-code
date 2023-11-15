static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

int
maximumElementAfterDecrementingAndRearranging(int* arr, int arr_size)
{
  int maximum = 1;
  qsort(arr, arr_size, sizeof(int), compare_ints);
  arr[0] = 1;
  for (int i = 1; i < arr_size; ++i) {
    if (arr[i - 1] + 1 < arr[i])
      arr[i] = arr[i - 1] + 1;
    if (arr[i] > maximum)
      maximum = arr[i];
  }
  return maximum;
}