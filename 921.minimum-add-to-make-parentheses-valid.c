// @leet start
int
minAddToMakeValid(char* s)
{
  int d = 0, ans = 0;
  for (int i = 0; s[i]; ++i)
    if (s[i] == '(')
      ++d;
    else if (d > 0)
      --d;
    else
      ++ans;
  return ans + d;
}
// @leet end