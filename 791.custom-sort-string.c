// @leet start

static int w[26];

static int
compare_chars(void const* a, void const* b)
{
  return w[*(char const*)a - 'a'] - w[*(char const*)b - 'a'];
}

char*
customSortString(char* order, char* s)
{
  memset(w, 0, 26 * sizeof(int));
  for (int i = 0; order[i] != 0; ++i)
    w[order[i] - 'a'] = i;
  qsort(s, strlen(s), sizeof(char), compare_chars);
  return s;
}
// @leet end