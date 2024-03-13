// @leet start
int
pivotInteger(int n)
{
  int s = (1 + n) * n / 2;
  int x = sqrt(s);
  return x * x == s ? x : -1;
}
// @leet end