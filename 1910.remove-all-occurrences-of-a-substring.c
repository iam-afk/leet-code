// @leet start
char*
removeOccurrences(char* s, char* part)
{
  int k = 0, m = strlen(part);
  for (int i = 0; s[i]; ++i) {
    s[k++] = s[i];
    if (k >= m && memcmp(s + k - m, part, m) == 0)
      k -= m;
  }
  s[k] = 0;
  return s;
}
// @leet end