// @leet start
int
pivotInteger(int n)
{
  int l = 1, r = n + 1, s = (1 + n) * n / 2;
  while (l < r) {
    int m = l + (r - l) / 2;
    if (m * m == s)
      return m;
    if (m * m < s)
      l = m + 1;
    else
      r = m;
  }
  return -1;
}
// @leet end