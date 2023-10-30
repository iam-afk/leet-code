int
compareInts(void const* a, void const* b)
{
  return *(int*)a - *(int*)b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int*
sortByBits(int* arr, int arrSize, int* returnSize)
{
  for (int i = 0; i < arrSize; ++i) {
    int c = 0, n = arr[i];
    while (n > 0) {
      ++c;
      n = n & (n - 1);
    }
    arr[i] |= c << 16;
  }
  qsort(arr, arrSize, sizeof *arr, compareInts);
  for (int i = 0; i < arrSize; ++i)
    arr[i] &= 0xffff;
  *returnSize = arrSize;
  return arr;
}