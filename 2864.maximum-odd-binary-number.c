// @leet start
char*
maximumOddBinaryNumber(char* s)
{
  int ones = 0, n = 0;
  for (n = 0; s[n] != 0; ++n)
    if (s[n] == '1')
      ++ones;
  int j = 0;
  for (int i = 0; i < ones - 1; ++i)
    s[j++] = '1';
  while (j < n - 1)
    s[j++] = '0';
  s[j] = '1';
  return s;
}
// @leet end