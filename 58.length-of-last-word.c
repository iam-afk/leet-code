// @leet start
int
lengthOfLastWord(char* s)
{
  int a, l = 0;
  for (int i = 0; s[i] != 0; ++i) {
    if (s[i] == ' ')
      l = 0;
    else
      ++l;
    if (l > 0)
      a = l;
  }
  return l > 0 ? l : a;
}
// @leet end