// @leet start

int
prefixCount(char** words, int wordsSize, char* pref)
{
  int ans = 0;
  for (int i = 0; i < wordsSize; ++i) {
    bool prefix = true;
    for (int j = 0; prefix && pref[j]; ++j)
      prefix = words[i][j] == pref[j];
    ans += prefix;
  }
  return ans;
}
// @leet end