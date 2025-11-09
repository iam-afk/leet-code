// @leet start
int
countOperations(int num1, int num2)
{
  int ans = 0;
  while (num2 != 0) {
    ans += num1 / num2;
    int t = num2;
    num2 = num1 % num2;
    num1 = t;
  }
  return ans;
}
// @leet end