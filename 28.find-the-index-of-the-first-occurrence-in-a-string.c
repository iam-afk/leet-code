// @leet start
int
strStr(char* haystack, char* needle)
{
  int n = strlen(haystack), m = strlen(needle);
  for (int i = 0; i + m <= n; ++i)
    if (memcmp(haystack + i, needle, m) == 0)
      return i;
  return -1;
}
// @leet end