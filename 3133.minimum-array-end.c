// @leet start
long long
minEnd(int n, int x)
{
  long long y = x, m = n - 1, i = 0;
  for (; x > 0; ++i, x >>= 1)
    if ((x & 1) == 0) {
      y |= (m & 1) << i;
      m >>= 1;
    }
  return y | m << i;
}
// @leet end