// @leet start
char*
makeFancyString(char* s)
{
  int j = 0;
  for (int i = 0; s[i]; ++i)
    if (j < 2 || s[j - 1] != s[j - 2] || s[i] != s[j - 1])
      s[j++] = s[i];
  s[j] = 0;
  return s;
}
// @leet end