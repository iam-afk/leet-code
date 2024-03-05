// @leet start
int
minimumLength(char* s)
{
  int i = 0, j = strlen(s) - 1;
  while (i < j && s[i] == s[j]) {
    char c = s[i];
    while (i <= j && s[i] == c)
      ++i;
    while (i <= j && s[j] == c)
      --j;
  }
  return j - i + 1;
}
// @leet end