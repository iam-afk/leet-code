// @leet start
int
myAtoi(char* s)
{
  int i = 0;
  while (s[i] == ' ')
    ++i;
  int sign = 1;
  if (s[i] == '-')
    sign = -1;
  else if (s[i] == '+')
    sign = 1;
  else
    --i;
  ++i;
  int n = 0;
  while ('0' <= s[i] && s[i] <= '9') {
    int d = s[i] - '0';
    if ((INT_MAX - d) / 10 < n)
      return INT_MAX;
    if ((INT_MIN + d) / 10 > n)
      return INT_MIN;
    n = n * 10 + sign * d;
    ++i;
  }
  return n;
}
// @leet end