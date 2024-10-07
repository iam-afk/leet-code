// @leet start
int
minLength(char* s)
{
  int j = -1;
  for (int i = 0; s[i]; ++i)
    if (j >= 0 && (s[j] == 'A' && s[i] == 'B' || s[j] == 'C' && s[i] == 'D'))
      --j;
    else
      s[++j] = s[i];
  return j + 1;
}
// @leet end