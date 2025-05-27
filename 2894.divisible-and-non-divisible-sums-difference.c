// @leet start
int
differenceOfSums(int n, int m)
{
  int sum = (1 + n) * n / 2;
  int k = n / m;
  return sum - (m + k * m) * k;
}
// @leet end