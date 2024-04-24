// @leet start

int
tribonacci(int n)
{
  int t = 0, t1 = 0, t2 = 1;
  for (int i = 0; i < n; ++i) {
    int x = t2;
    t2 = t1;
    t1 = t;
    t = t1 + t2 + x;
  }
  return t;
}
// @leet end