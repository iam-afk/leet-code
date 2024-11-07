// @leet start
int
largestCombination(int* candidates, int candidatesSize)
{
  int sizes[32] = {};
  for (int i = 0; i < candidatesSize; ++i) {
    int n = candidates[i];
    for (int i = 0; n > 0; ++i, n >>= 1)
      if (n & 1)
        ++sizes[i];
  }
  int ans = 0;
  for (int i = 0; i < 32; ++i)
    if (ans < sizes[i])
      ans = sizes[i];
  return ans;
}
// @leet end