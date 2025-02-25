// @leet start
int
numOfSubarrays(int* arr, int arrSize)
{
  int res = 0, odd = 0;
  for (int i = 0; i < arrSize; ++i) {
    if ((arr[i] & 1) == 1)
      odd = i - odd + 1;
    res += odd;
    res %= (int)1e9 + 7;
  }
  return res;
}
// @leet end