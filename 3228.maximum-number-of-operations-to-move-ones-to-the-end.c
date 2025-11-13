// @leet start
int
maxOperations(char* s)
{
  int ans = 0, z = 0;
  int n = strlen(s);
  while (n-- > 0)
    if (s[n] == '1')
      ans += z;
    else if (s[n + 1] == '1' || s[n + 1] == 0)
      ++z;
  return ans;
}
// @leet end