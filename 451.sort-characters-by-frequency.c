// @leet start

int counts[128];

static int
compare_by_counts(void const* a, void const* b)
{
  return counts[*(char const*)b] - counts[*(char const*)a];
}

char*
frequencySort(char* s)
{
  memset(counts, 0, sizeof counts);
  int len;
  for (len = 0; s[len]; ++len)
    ++counts[s[len]];
  char letters[128];
  for (int i = 0; i < 128; ++i)
    letters[i] = i;
  qsort(letters, 128, sizeof *letters, compare_by_counts);
  int i = 0;
  for (int j = 0; j < 128 && letters[j]; ++j)
    while (counts[letters[j]]-- > 0)
      s[i++] = letters[j];
  return s;
}
// @leet end