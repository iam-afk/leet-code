// @leet start
int
minChanges(char* s)
{
  int ans = 0;
  for (int i = 0; s[i]; i += 2)
    if (s[i] != s[i + 1])
      ++ans;
  return ans;
}
// @leet end