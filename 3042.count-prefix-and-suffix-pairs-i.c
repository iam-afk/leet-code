// @leet start
static bool
isPrefixAndSuffix(char* s1, char* s2)
{
  size_t n = strlen(s1), m = strlen(s2);
  if (n > m)
    return false;
  for (int i = 0; i < n; ++i)
    if (s1[i] != s2[i] || s1[i] != s2[m - n + i])
      return false;
  return true;
}

int
countPrefixSuffixPairs(char** words, int wordsSize)
{
  int ans = 0;
  for (int i = 0; i < wordsSize; ++i)
    for (int j = i + 1; j < wordsSize; ++j)
      if (isPrefixAndSuffix(words[i], words[j]))
        ++ans;
  return ans;
}
// @leet end