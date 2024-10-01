// @leet start
bool
canArrange(int* arr, int arrSize, int k)
{
  static int rems[100000];
  memset(rems, 0, k * sizeof(int));
  for (int i = 0; i < arrSize; ++i)
    ++rems[((arr[i] % k) + k) % k];
  bool ans = rems[0] % 2 == 0;
  for (int i = 1, j = k - 1; ans && i <= j; ++i, --j)
    if (i == j)
      ans = rems[i] % 2 == 0;
    else
      ans = rems[i] == rems[j];
  return ans;
}
// @leet end