// @leet start

static int
compare_ints(void const* a, void const* b)
{
  return *(int const*)a - *(int const*)b;
}

bool
closeStrings(char* word1, char* word2)
{
  int n1[26] = {}, n2[26] = {};
  int len1 = 0, len2 = 0;
  while (word1[len1] != 0)
    ++n1[word1[len1++] - 'a'];
  while (word2[len2] != 0)
    ++n2[word2[len2++] - 'a'];
  if (len1 != len2)
    return false;
  for (int i = 0; i < 26; ++i)
    if (n1[i] == 0 && n2[i] != 0 || n1[i] != 0 && n2[i] == 0)
      return false;
  qsort(n1, 26, sizeof(int), compare_ints);
  qsort(n2, 26, sizeof(int), compare_ints);
  for (int i = 0; i < 26; ++i)
    if (n1[i] != n2[i])
      return false;
  return true;
}
// @leet end