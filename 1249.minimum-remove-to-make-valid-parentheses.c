// @leet start
char*
minRemoveToMakeValid(char* s)
{
  int n = strlen(s);
  char* t = malloc(n + 1);
  int j = 0, d = 0;
  for (int i = 0; s[i] != 0; ++i) {
    if (s[i] == '(')
      ++d;
    else if (s[i] == ')')
      --d;
    if (d >= 0)
      t[j++] = s[i];
    else
      ++d;
  }
  int k = j;
  while (d > 0)
    if (t[--k] == '(')
      --d;
  int x = k;
  for (; k < j; ++k)
    if (t[k] != '(')
      t[x++] = t[k];

  t[x] = 0;
  return t;
}
// @leet end