// @leet start
char*
clearDigits(char* s)
{
  int i = 0;
  for (int j = 0; s[j]; ++j)
    if ('0' <= s[j] && s[j] <= '9')
      --i;
    else
      s[i++] = s[j];
  s[i] = 0;
  return s;
}
// @leet end