// @leet start
int
findSpecialInteger(int* arr, int arrSize)
{
  int d = arrSize / 4;
  for (int i = d; i < arrSize; ++i)
    if (arr[i - d] == arr[i])
      return arr[i];
  return arr[0];
}
// @leet end